#include <cmath>
#include <iostream>

class Point
{
  Point(float x, float y) : x(x), y(y) {}

  class PointFactory
  {
    PointFactory() {}
  public:
    static Point NewCartesian(float x, float y)
    {
      return { x,y };
    }
    static Point NewPolar(float r, float theta)
    {
      return{ r*cos(theta), r*sin(theta) };
    }
  };
public:
  float x, y;
  static PointFactory Factory;
};

int main()
{
  auto pp = Point::Factory.NewCartesian(4.0, 5.0);

  std::cout << "cartesian x:" << pp.x << " y:" << pp.y << std::endl;
  return 0;
}