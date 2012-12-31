// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "world/world_map.h"
#include <stddef.h>
#include <sstream>
#include <string>
#include <vector>
#include "units/map_unit.h"
#include "units/upgradable_unit.h"
#include "units/random_cost_unit.h"
#include "units/jail_unit.h"
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
    for (auto& ptr : units_) {
        delete ptr;
    }
}

void WorldMap::LoadMap(FILE* file) {
    string line;
    for (int i = 0 ;; ++i) {
        line = GetLine(file);
        if (line.size() == 0) { break; }

        units_.push_back(NewUnitByString(line, i));
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

MapUnit* WorldMap::NewUnitByString(const std::string& unit_info, const int id) {
    stringstream ss(unit_info);
    char unit_symbol;
    int cost;
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
            (id, name, world_player_->player_num(), cost, upgrade_cost, fines);
    break;

    case 'R':
        int base_fine;
        ss >> cost >> base_fine;
        return new RandomCostUnit
            (id, name, world_player_->player_num(), cost, base_fine);
    break;

    case 'J':
        return new JailUnit
            (id, name, world_player_->player_num());
    break;

    default:
        perror("Error at WorldMap::LoadMap : Unknown symbol read.\n");
        exit(EXIT_FAILURE);
    }
}
