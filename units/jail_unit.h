// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef UNITS_JAIL_UNIT_H_
#define UNITS_JAIL_UNIT_H_

#include <string>
#include "units/map_unit.h"

class JailUnit : public MapUnit {
 public:
    explicit JailUnit(int id, const std::string& name, int player_num);

    // override MapUnit
    void TravelEven(Player* traveler);
    void PrintInfo()const;
};

#endif  // UNITS_JAIL_UNIT_H_
