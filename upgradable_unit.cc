#include "upgradable_unit.h"

UpgradableUnit::UpgradableUnit
(const std::string& name, int cost, int upgrade_cost,
 const std::vector<int>& fines)
  :PayUnit(name, cost), _upgrade_cost_(upgrade_cost),
   _level_(0), _fines_(fines) {}

