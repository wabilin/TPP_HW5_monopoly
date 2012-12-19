#ifndef MAP_UNIT_H
#define MAP_UNIT_H

#include <string>


class MapUnit{
public:
    explicit MapUnit(std::string name):_name_(name){}
    virtual ~MapUnit() = 0;

    std::string name(){ return _name_; }

protected:
    std::string _name_;

private:
};

#endif // MAP_UNIT_H
