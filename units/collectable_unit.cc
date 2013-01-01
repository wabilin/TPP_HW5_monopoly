// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include "units/collectable_unit.h"
#include <cstdio>
#include <map>

using std::map;

map<int, int> CollectableUnit::s_players_cunits_map;

CollectableUnit::CollectableUnit
(int id, const std::string& name, int players_num, int cost, int base_fine)
  :PayUnit(id, name, players_num, cost), base_fine_(base_fine) {}

int CollectableUnit::fine() const {
    return base_fine_ * owner_cunits_num();
}


void CollectableUnit::Release() {
    // s_players_cunits_map[owner_id()] = 0;
    owner_ = nullptr;
}

void CollectableUnit::TravelEven(Player* traveler) {
    if (CanBuyBy(traveler)) {
        AskBuy(traveler);

        // traveler bought this unit
        if (!Abandoned()) {
            owner_cunits_num_inc();
        }
    } else if (NeedFine(traveler)) {
        AskPay(traveler);
    }
}

void CollectableUnit::PrintInfo() const {
    PrintBasicInfo();

    if (Abandoned()) {
        printf("    B$%5d   ", cost());
    } else {
        printf("(%d) x%d        ", owner_id(), owner_cunits_num());
    }
}

int CollectableUnit::owner_cunits_num() const {
    return s_players_cunits_map[owner_id()];
}

void CollectableUnit::owner_cunits_num_inc() {
    ++s_players_cunits_map[owner_id()];
}
