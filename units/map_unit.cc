// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "units/map_unit.h"

MapUnit::MapUnit(int id, const std::string& name, int player_num)
  :id_(id), name_(name), here_players_(player_num, false) {}


void MapUnit::PrintBasicInfo()const {
    // show player here
    putchar('=');
    for (unsigned i = 0 ; i < here_players_.size() ; ++i) {
        if (here_players_[i]) {
            printf("%u", i);
        } else {
            printf(" ");
        }
    }
    putchar('=');

    // show unit name & id
    printf("  [%d]%10s ", id(), name().c_str());
}

void MapUnit::PlayerCome(int player_id) {
    here_players_[player_id] = true;
}
void MapUnit::PlayerGo(int player_id) {
    here_players_[player_id] = false;
}
