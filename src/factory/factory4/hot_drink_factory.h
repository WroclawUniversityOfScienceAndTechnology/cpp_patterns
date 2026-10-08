#pragma once
#include "hot_drink.h"

// abstract factory
struct HotDrinkFactory
{
  virtual unique_ptr<HotDrink> make() const = 0;
};