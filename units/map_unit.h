// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef MAP_UNIT_H_
#define MAP_UNIT_H_

#include <string>
#include <vector>

class Player;

class MapUnit {
 public:
    explicit MapUnit(int id, const std::string& name, int players_num);
    virtual ~MapUnit() {}

    int id() const { return id_; }
    const std::string& name() const { return name_; }

    // to reflash here_players_
    void PlayerCome(int player_id);
    void PlayerGo(int player_id);

    virtual void PrintInfo () const = 0;

    // call even while a player is traveling the unit
    virtual void TravelEven(Player* traveler) = 0;

 protected:
    const int id_;
    const std::string name_;
    std::vector<bool> here_players_;

    // print players here and unit id & name
    void PrintBasicInfo() const;
};

#endif  // MAP_UNIT_H_
