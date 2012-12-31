// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef WORLD_WORLD_MAP_H_
#define WORLD_WORLD_MAP_H_

#include <vector>
#include <cstdio>

class MapUnit;
class Player;
class WorldPlayer;

class WorldMap {
 public:
    WorldMap(const WorldMap&) = delete;
    explicit WorldMap(WorldPlayer* world_player);
    virtual ~WorldMap();

    unsigned size()const { return units_.size(); }
    MapUnit* unit(int i) { return units_[i]; }
    const MapUnit* unit(int i) const { return units_[i]; }

    void LoadMap(FILE* map_file);
    void Print()const;

    void MovePlayer(int player_id, int unit_id);

 private:
    // pointers to new units # NEED dealloca #
    std::vector<MapUnit*> units_;

    // relate to players,
    // ## DO NOT use this as the only pointer to a new object ##
    WorldPlayer* world_player_;

    // init location, should called by LoadMap()
    void InitPlayersLocation();
};

#endif  // WORLD_WORLD_MAP_H_
