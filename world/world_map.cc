#include "world_map.h"
#include <stddef.h>
#include "units/map_unit.h"

WorldMap::~WorldMap() {
    for(size_t i = 0 ; i < units_.size() ; ++i){
        delete units_[i];
    }
}

