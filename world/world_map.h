#ifndef WORLD_MAP_H_
#define WORLD_MAP_H_

#include <vector>
#include <cstdio>

class MapUnit;
class Player;

class WorldMap {
 public:
    WorldMap(const WorldMap&) = delete;
    explicit WorldMap(int players_num);
    virtual ~WorldMap();

    void LoadMap(FILE* map_file);

 private:
    std::vector<MapUnit*> units_;
    int players_num_;
};

#endif // WORLD_MAP_H_INCLUDED
