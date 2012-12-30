#include "player/player.h"
#include <string>
using std::string;

Player::Player(int id, const string& name, int money)
  :id_(id), name_(name), money_(money), units_(0), move_point_(0) {}
