#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "graphic_object.h"

int main()
{
  Group root("root");
  Circle c1, c2;
  root.objects.push_back(&c1);

  Group subgroup1("sub1");
  subgroup1.objects.push_back(&c2);
  subgroup1.objects.push_back(&c2);

  Group subgroup2("subsub1");
  subgroup2.objects.push_back(&c2);

  root.objects.push_back(&subgroup1);
  subgroup1.objects.push_back(&subgroup2);

  root.draw();
  
  return 0;
}