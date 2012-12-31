// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "player/player.h"
#include <string>
#include "units/pay_unit.h"

using std::string;

Player::Player(int id, const string& name, int money)
  :id_(id), name_(name), money_(money), units_(0), location_(0), move_point_(0)
    {}

Player::~Player() {}

void Player::ReleaseUnits() {
    for (auto& unit : units_) {
        unit->Release();
    }
}
