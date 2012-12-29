// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include "units/pay_unit.h"
#include <cstdio>
#include <cctype>
#include <string>
#include "player/player.h"
#include "base/controll.h"
using std::string;

const string& PayUnit::owner_name() const {
    return owner_->name();
}

int PayUnit::owner_id() const {
    return owner_->id();
}

void PayUnit::AskBuy(Player* player) {
    static const size_t kMsgLength = 128;
    char msg[kMsgLength] = {'\0'};

    printf("%s, do you want to buy %s? (1: Yes [default] / 2: No) ...>",
           player->name().c_str(), this->name().c_str());
    fgets(msg, kMsgLength, stdin);

    // do not buy
    if(toupper(msg[0]) == 'N') {
        return;
    }

    // to buy
    player->Pay(cost());
    owner_ = player;
    printf("You pay $%d to buy %s\n",  cost(), name().c_str());
    Pause();
}

void PayUnit::AskPay(Player* traveler) const {
    printf("%s, you must pay $%d to Player %d (%s)\n",
           traveler->name().c_str(), fine(), owner_id(), owner_name().c_str());
    Pause();

    traveler->Pay(fine());
    owner_->Gain(fine());
}
