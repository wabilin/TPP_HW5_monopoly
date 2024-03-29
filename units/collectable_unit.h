// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#ifndef UNITS_COLLECTABLE_UNIT_H_
#define UNITS_COLLECTABLE_UNIT_H_

#include <map>
#include <string>
#include "units/pay_unit.h"

class CollectableUnit : public PayUnit {
 public:
    explicit CollectableUnit
    (int id, const std::string& name, int players_num, int cost, int base_fine);

    // override MapUnit
    void TravelEven(Player* traveler);
    void PrintInfo() const;

    // override PayUnit
    int  fine() const;
    void Release();

 protected:
    int base_fine_;

    // { :player_id => #his_collectable_units }
    static std::map<int, int> s_players_cunits_map;

    int  owner_cunits_num() const;
    void owner_cunits_num_inc();
};

#endif  // UNITS_COLLECTABLE_UNIT_H_
