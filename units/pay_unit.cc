// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include "units/pay_unit.h"
#include <cstdio>
#include <cctype>
#include "player/player.h"

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
    else {
        player->spend_money(cost());
        printf("You pay $%d to buy Germany\n",  cost());
    }
}
