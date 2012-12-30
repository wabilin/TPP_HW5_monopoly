// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "map_unit.h"

MapUnit::MapUnit(const std::string& name, int player_num)
  :name_(name), here_players_(player_num, false) {}
