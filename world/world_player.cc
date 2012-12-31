#include "world/world_player.h"
#include "player/player.h"

WorldPlayer::WorldPlayer()
  :players_(0) {}

WorldPlayer::~WorldPlayer() {
    for(auto& ptr : players_) {
        delete ptr;
    }
}

void WorldPlayer::AddPlayer(Player* player) {
    players_.push_back(player);
}
