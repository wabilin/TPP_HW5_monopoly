#include "upgradable_unit.h"

UpgradableUnit::UpgradableUnit
(const std::string& name, int cost, int upgrade_cost,
 const std::vector<int>& fines)
  :PayUnit(name, cost), upgrade_cost_(upgrade_cost),
   level_(0), fines_(fines) {}

