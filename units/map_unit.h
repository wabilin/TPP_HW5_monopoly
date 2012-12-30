// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef MAP_UNIT_H_
#define MAP_UNIT_H_

#include <string>
#include <vector>

class Player;

class MapUnit {
 public:
    explicit MapUnit(const std::string& name, int player_num);
    virtual ~MapUnit() {}

    const std::string& name() { return name_; }

    virtual void PrintInfo () = 0;
    virtual void StopAct(Player*) = 0;

 protected:
    std::string name_;
    std::vector<bool> here_players_;
};

#endif  // MAP_UNIT_H_
