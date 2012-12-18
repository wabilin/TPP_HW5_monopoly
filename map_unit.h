#ifndef MAP_UNIT_H
#define MAP_UNIT_H

#include <string>


class MapUnit{
public:
    MapUnit();
    virtual ~MapUnit() = 0;

protected:
    int _id_;
    std::string _name_;

private:
};

#endif // MAP_UNIT_H
