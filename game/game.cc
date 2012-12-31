// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "game/game.h"
#include <cstdio>
#include <cstring>
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

    vector<string> player_names(players_num);
    for (int i = 0 ; i < players_num ; ++i) {
        printf("Please input player %d's name (Default: %s)...>",
               i+1, kDefaultPlayerNames[i].c_str());
        string name = GetLine();
        player_names[i] = (name.size() != 0)? name : kDefaultPlayerNames[i];
    }

    map_ = new WorldMap();
    map_->LoadMap(map_file, players_num);
}

void Game::MainLoop() {
    map_->Print();
}
