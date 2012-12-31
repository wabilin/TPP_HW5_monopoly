// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstdio>
#include <string>
#include <vector>

class WorldMap;
class WorldPlayer;

class Game {
 public:
    Game();
    ~Game();
    void InitGame(FILE* map_file);

 private:
    WorldMap* map_;
    WorldPlayer* world_player_;

    static const std::vector<std::string> kDefaultPlayerNames;
};

#endif  // GAME_GAME_H_
