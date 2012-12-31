// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "world/world_map.h"
#include <stddef.h>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include "units/map_unit.h"
#include "units/upgradable_unit.h"
#include "world/world_player.h"
#include "player/player.h"

using std::string;
using std::vector;
using std::array;
using std::stringstream;

WorldMap::WorldMap(WorldPlayer* world_player)
  :world_player_(world_player) {}

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
    while (fgets(line, kLineLength, file)) {
        stringstream ss(line);
        ss >> unit_symbol >> name;

        switch (unit_symbol) {
        case 'U':
            int cost, upgrade_cost;
            array<int, UpgradableUnit::kLevelNum> fines;
            ss >> cost >> upgrade_cost;
            for (auto& fine : fines) {
                ss >> fine;
            }
            units_.push_back(new UpgradableUnit
                (id, name, world_player_->player_num(), cost, upgrade_cost, fines));
        break;

        default:
            perror("Error at WorldMap::LoadMap : Unknown symbol read.\n");
            break;
        }

        ++id;
    }

    if (units_.size() % 2 != 0) {
        perror("Error at WorldMap::LoadMap: Odd num units.\n");
    }

    InitPlayersLocation();
}

void WorldMap::Print()const {
    const size_t kHalfNum = units_.size() / 2;
    const size_t kLastId = units_.size() - 1;
    for (size_t i = 0 ; i < kHalfNum ; ++i) {
        units_[i]->PrintInfo();
        printf("    ");
        units_[kLastId- i]->PrintInfo();
        putchar('\n');
    }
}

void WorldMap::MovePlayer(int player_id, int unit_id) {
    Player* player = world_player_->player(player_id);
    int old_location = player->location();

    player->move_location(unit_id);

    units_[old_location]->PlayerGo(player_id);
    units_[unit_id]->PlayerCome(player_id);
}


void WorldMap::InitPlayersLocation() {
    for (int i = 0 ; i < world_player_->player_num() ; ++i) {
        units_[0]->PlayerCome(i);
    }
}
