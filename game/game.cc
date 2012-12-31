// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "game/game.h"
#include <cstdio>
#include <cstring>
#include "player/player.h"
#include "world/world_map.h"
#include "world/world_player.h"
#include "base/controll.h"

using std::string;
using std::vector;

const vector<string>
Game::kDefaultPlayerNames({"A-Tu", "Little-Mei", "King-Baby", "Mrs.Money"});

Game::Game()
  :map_(nullptr), world_player_(nullptr) {}

Game::~Game() {
    delete map_;
    delete world_player_;
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
    map_->Print();
}
