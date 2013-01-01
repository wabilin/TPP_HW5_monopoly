// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "world/world_player.h"
#include "player/player.h"

WorldPlayer::WorldPlayer()
  :players_(0), on_turn_(0) {}

WorldPlayer::~WorldPlayer() {
    for (auto ptr : players_) {
        delete ptr;
    }
}

void WorldPlayer::NextTurn() {
    do {
        ++on_turn_;
        if (on_turn_ >= players_.size()) {
            on_turn_ = 0;
        }
    } while (players_[on_turn_] == nullptr);
}

void WorldPlayer::AddPlayer(Player* player) {
    players_.push_back(player);
}

void WorldPlayer::Print()const {
    for (const Player* player : players_) {
        if (player == nullptr) { continue; }

        if (player == PlayerOnTurn()) {
            printf("=>");
        } else {
            printf("  ");
        }

        printf("[%d]%18s  $%5d with %d units\n",
               player->id(), player->name().c_str(),
               player->money(), player->units_num());
    }
}

const Player* WorldPlayer::FindWinner() const {
    int live_count = 0;
    for (auto player : players_) {
        if (player != nullptr) { ++live_count; }
    }

    if (live_count > 1) {
        return nullptr;
    } else {
        Player* winner(nullptr);
        for (auto player : players_) {
            if (player != nullptr) { winner = player; }
        }
        if (winner == nullptr) {
            perror
            ("Error at WorldPlayer::FindWinner(): no one are able to win.\n");
            exit(EXIT_FAILURE);
        }

        return winner;
    }
}

void WorldPlayer::KillPlayer(int player_id) {
    delete players_[player_id];
    players_[player_id] = nullptr;
}
