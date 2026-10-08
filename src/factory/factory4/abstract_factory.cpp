#include <iostream>
#include <memory>
#include <map>
#include "hot_drink.h"
#include "drink_factory.h"
using namespace std;

//factory method
unique_ptr<HotDrink> make_drink(string type)
{
  unique_ptr<HotDrink> drink;
  if (type == "tea")
  {
    drink = make_unique<Tea>();
    drink->prepare(200);
  }
  else 
  {
    drink = make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

int main()
{
  // use factory method
  auto d = make_drink("tea");

  // use abstract factory
  DrinkFactory df;
  df.make_drink("coffee");

  DrinkWithVolumeFactory volume_df;
  volume_df.make_drink("tea");

  getchar();
  return 0;
}