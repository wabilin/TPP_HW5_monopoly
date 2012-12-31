// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef WORLD_WORLD_MAP_H_
#define WORLD_WORLD_MAP_H_

#include <vector>
#include <cstdio>

class MapUnit;
class Player;

class WorldMap {
 public:
    WorldMap(const WorldMap&) = delete;
    explicit WorldMap();
    virtual ~WorldMap();

    void LoadMap(FILE* map_file, int players_num);
    void Print()const;

 private:
    std::vector<MapUnit*> units_;
};

#endif  // WORLD_WORLD_MAP_H_
