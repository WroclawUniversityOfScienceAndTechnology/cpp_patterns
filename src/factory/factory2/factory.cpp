#include <cmath>
#include <iostream>

class Point
{
  Point(float x, float y) : x(x), y(y){}
public:
  float x, y;

  friend class PointFactory;
};

class PointFactory
{
  public:
    static Point NewCartesian(float x, float y)
    {
      return Point{ x,y };
    }

    static Point NewPolar(float r, float theta)
    {
      return Point{ r*cos(theta), r*sin(theta) };
    }
};

int main()
{
  auto cartesion = PointFactory::NewCartesian(4.0,5.0);
  auto polar = PointFactory::NewPolar(4.0, 5.0);

  std::cout << "cartesian x:" << cartesion.x << " y:" << cartesion.y << std::endl;
  std::cout << "polar x:" << polar.x << " y:" << polar.y << std::endl;

  return 0;
}