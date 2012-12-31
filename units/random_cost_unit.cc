#include "random_cost_unit.h"
#include "base/random_gen.h"

RandomGen RandomCostUnit::s_dice_(1, kDiceSurface);

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


