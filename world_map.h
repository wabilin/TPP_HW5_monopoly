#ifndef WORLD_MAP_H_INCLUDED
#define WORLD_MAP_H_INCLUDED XD

#include <memory>
#include <vector>

class MapUnit;

typedef std::unique_ptr<MapUnit> MapUnitPtr;

class WorldMap{
public:
private:
    std::vector<MapUnitPtr> _units_;
};

#endif // WORLD_MAP_H_INCLUDED
