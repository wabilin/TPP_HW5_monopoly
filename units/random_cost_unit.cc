// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include "units/random_cost_unit.h"
#include "base/random_gen.h"

RandomGen RandomCostUnit::s_dice_(1, kDiceSurface);

RandomCostUnit::RandomCostUnit
(int id, const std::string& name, int players_num, int cost, int base_fine)
  :PayUnit(id, name, players_num, cost), base_fine_(base_fine) {}

void RandomCostUnit::TravelEven(Player* traveler) {
    if (CanBuyBy(traveler)) {
        AskBuy(traveler);
    } else if (NeedFine(traveler)) {
        AskPay(traveler);
    }
}

void RandomCostUnit::PrintInfo() const {
    PrintBasicInfo();

    if (Abandoned()) {
        printf("    B$%5d   ", cost());
    } else {
        printf("(%d) ?         ", owner_id());
    }
}

int RandomCostUnit::fine() const {
    return base_fine_ * Dice();
}

void RandomCostUnit::Release() {
    owner_ = nullptr;
}

int RandomCostUnit::Dice() {
    return s_dice_();
}


