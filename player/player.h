// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef PLAYER_PLAYER_H_
#define PLAYER_PLAYER_H_

#include <string>

class Player {
 public:
    Player(int id, const std::string& name);
    virtual ~Player(){}

    const std::string& name()const { return name_; }
    int  move_point() const { return move_point_; }
    void set_move_point(int p) { move_point_ = p; }
    int money() const { return money_; }
    void gain_money(int m)  { money_ += m; }
    void spend_money(int m) { money_ -= m; }

    bool Crash() { return money() <= 0; }

 private:
    int id_;
    std::string name_;
    int money_;

    // times that player can dice in a turn
    int move_point_;
};

#endif  // PLAYER_PLAYER_H_
