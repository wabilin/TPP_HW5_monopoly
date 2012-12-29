// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "units/jail_unit.h"
#include "player/player.h"
#include "base/controll.h"

void JailUnit::StopAct(Player* player) {
    player->set_move_point(-1);

    printf("%s, you have been frozen :DDD\n", player->name().c_str());
    Pause();
}


