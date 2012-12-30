#include "world_map.h"
#include <stddef.h>
#include "units/map_unit.h"

WorldMap::WorldMap(int players_num)
  :players_num_(players_num) {}

WorldMap::~WorldMap() {
    for (auto& ptr : units_) {
        delete ptr;
    }
}

