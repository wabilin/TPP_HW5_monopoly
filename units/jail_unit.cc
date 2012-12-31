// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "units/jail_unit.h"
#include "player/player.h"
#include "base/controll.h"

JailUnit::JailUnit(int id, const std::string& name, int player_num)
  :MapUnit(id, name, player_num) {}

void JailUnit::TravelEven(Player* traveler) {
    traveler->set_move_point(-1);

    printf("%s, you have been frozen :DDD\n", traveler->name().c_str());
}

void JailUnit::PrintInfo()const {
    PrintBasicInfo();
    printf(" ^o^-c orz =: ");
}
