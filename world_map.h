#ifndef WORLD_MAP_H_INCLUDED
#define WORLD_MAP_H_INCLUDED XD

#include <memory>
#include <vector>

class MapUnit;

typedef std::unique_ptr<MapUnit> MapUnitPtr;

class WorldMap{
public:
    WorldMap(const WorldMap&) = delete;
    WorldMap();


private:
    std::vector<MapUnitPtr> units_;
};

#endif // WORLD_MAP_H_INCLUDED
