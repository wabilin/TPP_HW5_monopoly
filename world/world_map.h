// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef WORLD_WORLD_MAP_H_
#define WORLD_WORLD_MAP_H_

#include <cstdio>
#include <vector>
#include <string>

class MapUnit;
class Player;
class WorldPlayer;

class WorldMap {
 public:
    explicit WorldMap(WorldPlayer* world_player);
    virtual ~WorldMap();

    WorldMap(const WorldMap&) = delete;
    WorldMap& operator=(const WorldMap&) = delete;

    size_t size()const { return units_.size(); }
    MapUnit* unit(int i) { return units_[i]; }
    const MapUnit* unit(int i) const { return units_[i]; }

    void LoadMap(FILE* map_file);
    void Print()const;

    void MovePlayer(int player_id, int unit_id);

    // remove a player from map, non-deallocation
    void PlayerOut(const Player* player);

 private:
    // pointers to new units # NEED deallocation #
    std::vector<MapUnit*> units_;

    // relate to players,
    // ## DO NOT use this as the only pointer to a new object ##
    WorldPlayer* world_player_;

    // init location, should called by LoadMap()
    void InitPlayersLocation();

    // parse the string(unit info), return a new MapUnit object
    static MapUnit* NewUnitByString
    (const std::string& unit_info, const int id, const int player_num);
};

#endif  // WORLD_WORLD_MAP_H_
