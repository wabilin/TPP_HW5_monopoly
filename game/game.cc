// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "game/game.h"
#include <cstdio>
#include <cstring>
#include "player/player.h"
#include "units/map_unit.h"
#include "world/world_map.h"
#include "world/world_player.h"
#include "base/controll.h"
#include "base/random_gen.h"

using std::string;
using std::vector;

const vector<string>
Game::kDefaultPlayerNames({"A-Tu", "Little-Mei", "King-Baby", "Mrs.Money"});

Game::Game()
  :map_(nullptr), world_player_(nullptr), dice_(new RandomGen(1, kDiceSurface)) {}

Game::~Game() {
    delete map_;
    delete world_player_;
    delete dice_;
}

void Game::InitGame(FILE* map_file) {
    int players_num;
    printf("How many players?(Maximum:%d)...>",
            WorldPlayer::kMaxPlayerNum);
    scanf("%d%*c", &players_num);
    if (players_num < WorldPlayer::kMinPlayerNum
        || players_num > WorldPlayer::kMaxPlayerNum) {
            perror("Error at Game::GameInit(): wrong player num.\n");
    }

    world_player_ = new WorldPlayer();
    for (int i = 0 ; i < players_num ; ++i) {
        printf("Please input player %d's name (Default: %s)...>",
               i+1, kDefaultPlayerNames[i].c_str());
        string name = GetLine();
        name = (name.size() != 0)? name : kDefaultPlayerNames[i];
        world_player_->AddPlayer(new Player(i, name, kStartMoney));
    }

    map_ = new WorldMap(world_player_);
    map_->LoadMap(map_file);
}

void Game::MainLoop() {
    while (true) {
        ClearScreen();
        PrintGameInfo();

        printf("A-Tu, your action? (1:Dice [default] / 2:Exit)...>");  // 2 == No == Exit
        if (!GetYesOrNo()) { return; }

        Player* player = world_player_->PlayerOnTurn();
        player->set_move_point(player->move_point() + 1);

        while (player->move_point() > 0) {
            DiceAndMove(player);

            ClearScreen();
            PrintGameInfo();

            map_->unit(player->location())->TravelEven(player);

            player->set_move_point(player->move_point() - 1);
        }

        Pause();
        world_player_->NextTurn();
    }
}

void Game::PrintGameInfo() {
    map_->Print();
    putchar('\n');
    world_player_->Print();
    putchar('\n');
}

void Game::DiceAndMove(Player* player) {
    unsigned location = player->location() + Dice();
    while (location >= map_->size()) {
        player->Gain(kOPointReword);
        printf("You gained $%d reword.\n", kOPointReword);
        location -= map_->size();
    }
    map_->MovePlayer(player->id(), location);
}

int Game::Dice() const {
    return (*dice_)();
}
