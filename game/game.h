// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstdio>
#include <string>
#include <vector>

class WorldMap;
class WorldPlayer;
class Player;

class Game {
 public:
    Game();
    ~Game();
    void InitGame(FILE* map_file);
    void MainLoop();

 private:
    // pointers to new map and new players
    // # NEED dealloca #
    WorldMap* map_;
    WorldPlayer* world_player_;
    void PrintGameInfo();
    void DiceAndMove(Player* player);

    static const int kStartMoney = 30000;
    static const int kDiceSurface = 6;
    static const int kOPointReword = 400;
    static const std::vector<std::string> kDefaultPlayerNames;
};

#endif  // GAME_GAME_H_
