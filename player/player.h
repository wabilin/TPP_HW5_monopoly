// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef PLAYER_PLAYER_H_
#define PLAYER_PLAYER_H_

#include <string>
#include <vector>

class PayUnit;

class Player {
 public:
    Player(int id, const std::string& name, int money);
    virtual ~Player() {}

    int id() const { return id_; }
    const std::string& name()const { return name_; }

    int  move_point() const    { return move_point_; }
    void set_move_point(int p) { move_point_ = p; }
    int  location() const { return location_; }
    void move_location(int location) { location_ = location; }
    int  units_num() const     { return units_.size(); }

    int  money() const { return money_; }
    void Gain(int money) { money_ += money; }
    void Pay (int money) { money_ -= money; }
    void AddUnit(PayUnit* unit) { units_.push_back(unit); }

    bool Crash() const { return money() < 0; }

 private:
    const int id_;
    std::string name_;
    int money_;
    int location_;  // init = 0
    std::vector<PayUnit*> units_;

    // times that player can dice in a turn
    int move_point_;  // init = 0
};

#endif  // PLAYER_PLAYER_H_
