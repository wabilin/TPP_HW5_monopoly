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
    WorldPlayer(const WorldPlayer&) = delete;
    WorldPlayer& operator=(const WorldPlayer&) = delete;

    int player_num() const { return players_.size(); }
    Player* player(int id) { return players_[id]; }
    const Player* player(int id) const { return players_[id]; }

    Player*       PlayerOnTurn()       { return player(on_turn_); }
    const Player* PlayerOnTurn() const { return player(on_turn_); }

    // turn to next player
    void NextTurn();

    // please send a "new" player in
    void AddPlayer(Player* player);

    // return pointer to the winner if someone won
    // return nullptr, otherwise
    const Player* FindWinner() const;

    // to kill the loser
    // #NOTE# : player will be dealloca
    void KillPlayer(int player_id);

    void Print()const;

 private:
    std::vector<Player*> players_;
    unsigned on_turn_;
};

#endif  // WORLD_WORLD_PLAYER_H_
