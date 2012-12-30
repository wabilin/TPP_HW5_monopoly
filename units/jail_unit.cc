// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "units/jail_unit.h"
#include "player/player.h"
#include "base/controll.h"

JailUnit::JailUnit(int id, const std::string& name, int player_num)
  :MapUnit(id, name, player_num) {}

void JailUnit::StopAct(Player* player) {
    player->set_move_point(-1);

    printf("%s, you have been frozen :DDD\n", player->name().c_str());
    Pause();
}


