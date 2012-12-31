// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstdio>
#include <string>
#include <vector>

class WorldMap;
class WorldPlayer;
class Player;
class RandomGen;

class Game {
 public:
    Game();
    ~Game();
    void InitGame(FILE* map_file);
    void MainLoop();

 private:
    // pointers to new map, new players and new dice
    // # NEED to be deallocated #
    WorldMap* map_;
    WorldPlayer* world_player_;
    RandomGen* dice_;

    void PrintGameInfo()const;
    int  Dice() const;

    // move, if pass O-Unit, gain reword
    void MovePlayer(Player* player, int step);

    static const int kStartMoney = 30000;
    static const int kDiceSurface = 6;
    static const int kOPointReword = 400;
    static const std::vector<std::string> kDefaultPlayerNames;
};

#endif  // GAME_GAME_H_
