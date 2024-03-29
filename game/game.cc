// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "game/game.h"
#include <cstdio>
#include <cstdlib>
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
  :map_(nullptr), world_player_(nullptr), dice_(new RandomGen(1, kDiceSurface))
    {}

Game::~Game() {
    delete map_;
    delete world_player_;
    delete dice_;
}

void Game::InitGame(FILE* map_file) {
    int players_num;

    ClearScreen();
    printf("How many players?(Maximum:%d)...>",
            WorldPlayer::kMaxPlayerNum);
    scanf("%d%*c", &players_num);
    if (players_num < WorldPlayer::kMinPlayerNum
        || players_num > WorldPlayer::kMaxPlayerNum) {
            Die("Wrong player num (Game::GameInit)");
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

        Player* player = world_player_->PlayerOnTurn();
        player->set_move_point(player->move_point() + 1);

        while (player->move_point() > 0) {
            printf("%s, your action? (1:Dice [default] / 2:Exit)...>",
                   player->name().c_str());
            // 2 == No == Exit
            if (!GetYesOrNo()) { return; }
            player->set_move_point(player->move_point() - 1);
            MovePlayer(player, Dice());

            ClearScreen();
            PrintGameInfo();

            map_->unit(player->location())->TravelEven(player);
        }

        CheckCrashed(player);
        if (CheckWon()) { return; }

        Pause();
        world_player_->NextTurn();
    }
}

void Game::PrintGameInfo()const {
    map_->Print();
    putchar('\n');
    world_player_->Print();
    putchar('\n');
}

void Game::MovePlayer(Player* player, int step) {
    unsigned location = player->location() + step;
    while (location >= map_->size()) {
        player->Gain(kOPointReword);
        printf("You gained $%d reword.\n", kOPointReword);
        Pause();
        location -= map_->size();
    }
    map_->MovePlayer(player->id(), location);
}

int Game::Dice() const {
    return (*dice_)();
}

void Game::CheckCrashed(Player* player) {
     if (player->Crash()) {
        printf("%s crashed.\n", player->name().c_str());

        player->ReleaseUnits();
        map_->PlayerOut(player);
        world_player_->KillPlayer(player->id());
    }
}

bool Game::CheckWon() {
    if (world_player_->FindWinner() != nullptr) {
        const Player* winner = world_player_->FindWinner();
        printf("Player %d (%s) win!!\n",
               winner->id(), winner->name().c_str());
        Pause();
        return true;
    }

    return false;
}
