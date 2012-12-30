// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef UNITS_JAIL_UNIT_H_
#define UNITS_JAIL_UNIT_H_

#include <string>
#include "units/map_unit.h"

class JailUnit : public MapUnit {
 public:
    explicit JailUnit(const std::string& name, int player_num);
    void StopAct(Player* player);
};

#endif  // UNITS_JAIL_UNIT_H_
