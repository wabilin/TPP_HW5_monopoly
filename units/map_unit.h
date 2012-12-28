// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef MAP_UNIT_H_
#define MAP_UNIT_H_

#include <string>

class Player;

class MapUnit {
 public:
    explicit MapUnit(const std::string& name):name_(name) {}
    virtual ~MapUnit() {}

    const std::string& name() { return name_; }

    virtual void StopAct(Player&) = 0;

 protected:
    std::string name_;
};

#endif  // MAP_UNIT_H_
