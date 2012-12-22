#ifndef MAP_UNIT_H
#define MAP_UNIT_H

#include <string>

class Player;

class MapUnit{
public:
    explicit MapUnit(const std::string& name):_name_(name){}
    virtual ~MapUnit(){}

    const std::string& name(){ return _name_; }

    virtual void StopAct(Player&) = 0;

protected:
    std::string _name_;
};

#endif // MAP_UNIT_H
