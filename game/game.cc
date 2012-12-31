// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "game/game.h"
#include <cstdio>
#include <cstring>
#include "world/world_map.h"
#include "world/world_player.h"

using std::string;
using std::vector;

const vector<string>
kDefaultPlayerNames = {"A-Tu", "Little-Mei", "King-Baby", "Mrs.Money"};

Game::Game()
  :map_(nullptr), world_player_(nullptr) {}

Game::~Game() {
    delete map_;
    delete world_player_;
}

void Game::InitGame(FILE* map_file) {
    int player_num;
    printf("How many players?(Maximum:%d)...>",
            WorldPlayer::kMaxPlayerNum);
    scanf("%d%*c", &player_num);
    if (player_num < WorldPlayer::kMinPlayerNum
        || player_num > WorldPlayer::kMaxPlayerNum) {
            perror("Error at Game::GameInit(): wrong player num.\n");
    }

    vector<string> player_names(player_num);
    for (int i = 0 ; i < player_num ; ++i) {

    }
}
