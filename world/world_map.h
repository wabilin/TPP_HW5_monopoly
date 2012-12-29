#ifndef WORLD_MAP_H_
#define WORLD_MAP_H_

#include <vector>

class MapUnit;

class WorldMap{
public:
    WorldMap(const WorldMap&) = delete;
    virtual ~WorldMap();

private:
    std::vector<MapUnit*> units_;
};

#endif // WORLD_MAP_H_INCLUDED
