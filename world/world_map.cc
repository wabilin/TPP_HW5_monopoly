// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "world/world_map.h"
#include <sstream>
#include <string>
#include <vector>
#include "units/map_unit.h"
#include "units/upgradable_unit.h"
#include "units/random_cost_unit.h"
#include "units/jail_unit.h"
#include "units/collectable_unit.h"
#include "world/world_player.h"
#include "player/player.h"
#include "base/controll.h"

using std::string;
using std::vector;
using std::array;
using std::stringstream;

WorldMap::WorldMap(WorldPlayer* world_player)
  :world_player_(world_player) {}

WorldMap::~WorldMap() {
    for (auto ptr : units_) {
        delete ptr;
    }
}

void WorldMap::LoadMap(FILE* file) {
    string line;
    for (int i = 0 ;; ++i) {
        line = GetLine(file);
        if (line.size() == 0) { break; }

        units_.push_back(NewUnitByString(line, i, world_player_->player_num()));
    }

    if (units_.size() % 2 != 0) {
        Die("Odd num units. (WorldMap::LoadMap)");
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

    units_[player->location()]->PlayerGo(player_id);
    units_[unit_id]->PlayerCome(player_id);
    player->move_location(unit_id);
}


void WorldMap::InitPlayersLocation() {
    for (int i = 0 ; i < world_player_->player_num() ; ++i) {
        units_[0]->PlayerCome(i);
    }
}

MapUnit* WorldMap::NewUnitByString
(const std::string& unit_info, const int id, const int player_num) {
    stringstream ss(unit_info);
    char unit_symbol;
    int cost, base_fine;
    string name;
    ss >> unit_symbol >> name;

    switch (unit_symbol) {
    case 'U':
        int upgrade_cost;
        array<int, UpgradableUnit::kLevelNum> fines;
        ss >> cost >> upgrade_cost;
        for (auto& fine : fines) {
            ss >> fine;
        }
        return new UpgradableUnit
            (id, name, player_num, cost, upgrade_cost, fines);
    break;

    case 'R':
        ss >> cost >> base_fine;
        return new RandomCostUnit
            (id, name, player_num, cost, base_fine);
    break;

    case 'C':
        ss >> cost >> base_fine;
        return new CollectableUnit
            (id, name, player_num, cost, base_fine);
    break;

    case 'J':
        return new JailUnit
            (id, name, player_num);
    break;

    default:
        Die("Unknown symbol read. (WorldMap::NewUnitByString)");
        return nullptr;  // to avoid compiler waring, never go to this line
    }
}

void WorldMap::PlayerOut(const Player* player) {
    unit(player->location())->PlayerGo(player->id());
}
