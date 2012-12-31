// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include "units/pay_unit.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "player/player.h"
#include "base/controll.h"
using std::string;

PayUnit::PayUnit(int id, const std::string& name, int players_num, int cost)
  :MapUnit(id, name, players_num), cost_(cost), owner_(nullptr) {}


const string& PayUnit::owner_name() const {
    return owner_->name();
}

int PayUnit::owner_id() const {
    return owner_->id();
}

bool PayUnit::CanBuyBy(const Player* traveler) const {
    return Abandoned() && traveler->money() > cost();
}

bool PayUnit::NeedFine(const Player* traveler)const {
    return !Abandoned() && owner_id() != traveler->id();
}

void PayUnit::AskBuy(Player* traveler) {
    printf("%s, do you want to buy %s? (1: Yes [default] / 2: No) ...>",
           traveler->name().c_str(), this->name().c_str());

    // buy
    if (GetYesOrNo()) {
        traveler->Pay(cost());
        owner_ = traveler;
        traveler->AddUnit(this);
        printf("You pay $%d to buy %s\n",  cost(), name().c_str());
    }
}

void PayUnit::AskPay(Player* traveler) const {
    int fixed_fine = fine();
    printf("%s, you must pay $%d to Player %d (%s)\n",
           traveler->name().c_str(), fixed_fine, owner_id(), owner_name().c_str());

    traveler->Pay(fixed_fine);
    owner_->Gain(fixed_fine);
}
