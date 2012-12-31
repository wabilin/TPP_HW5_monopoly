#ifndef WORLD_WORLD_PLAYER_H_
#define WORLD_WORLD_PLAYER_H_

#include <vector>

class Player;

class WorldPlayer {
 public:
    static const int kMaxPlayerNum = 4;
    static const int kMinPlayerNum = 1;

    WorldPlayer();
    ~WorldPlayer();

    int player_num() const { return players_.size(); }
    Player* player(int id) { return players_[id]; }
    const Player* player(int id) const { return players_[id]; }

    // please send a "new" player in
    void AddPlayer(Player* player);

 private:
    std::vector<Player*> players_;
};

#endif  // WORLD_WORLD_PLAYER_H_
