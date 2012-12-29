#include "player/player.h"
#include <string>
using std::string;

Player::Player(int id, const string& name)
  :id_(id), name_(name) {}
