#include "world_map.h"
#include <stddef.h>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include "units/map_unit.h"
#include "units/upgradable_unit.h"
using std::string;
using std::vector;
using std::array;
using std::stringstream;

WorldMap::WorldMap(int players_num)
  :players_num_(players_num) {}

WorldMap::~WorldMap() {
    for (auto& ptr : units_) {
        delete ptr;
    }
}

void WorldMap::LoadMap(FILE* file) {
    static const size_t kLineLength = 128;
    char line[kLineLength] = {'\0'};

    int id = 0;
    string name;
    char unit_symbol;
    while(fgets(line, kLineLength, file)) {
        stringstream ss(line);
        ss >> unit_symbol >> name;

        switch (unit_symbol) {
        case 'U':
            int cost, upgrade_cost;
            array<int, UpgradableUnit::kLevelNum> fines;
            ss >> cost >> upgrade_cost;
            for(auto& fine : fines) {
                ss >> fine;
            }
            units_.push_back
              (new UpgradableUnit(id, name, players_num_, cost, upgrade_cost, fines));
        break;

        default:
            perror("Error at WorldMap::LoadMap : Unknown symbol read.\n");
            break;
        }

        ++id;
    }
}
