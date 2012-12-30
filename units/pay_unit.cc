// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include "units/pay_unit.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "player/player.h"
#include "base/controll.h"
using std::string;

PayUnit::PayUnit(const std::string& name, int player_num, int cost)
  :MapUnit(name, player_num), cost_(cost), owner_(nullptr) {}


const string& PayUnit::owner_name() const {
    return owner_->name();
}

int PayUnit::owner_id() const {
    return owner_->id();
}

bool PayUnit::CanBuyBy(const Player* traveler) const {
    return traveler->money() > cost();
}

void PayUnit::AskBuy(Player* traveler) {
    printf("%s, do you want to buy %s? (1: Yes [default] / 2: No) ...>",
           traveler->name().c_str(), this->name().c_str());

    // buy
    if (GetYesOrNo()) {
        traveler->Pay(cost());
        owner_ = traveler;
        printf("You pay $%d to buy %s\n",  cost(), name().c_str());
        Pause();
    }
}

void PayUnit::AskPay(Player* traveler) const {
    printf("%s, you must pay $%d to Player %d (%s)\n",
           traveler->name().c_str(), fine(), owner_id(), owner_name().c_str());
    Pause();

    traveler->Pay(fine());
    owner_->Gain(fine());
}
