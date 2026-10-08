#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Shape
{
  virtual string str() const = 0;
};

struct Circle : Shape
{
  float radius;

  Circle(){}

  explicit Circle(const float radius)
    : radius{radius}
  {
  }

  void resize(float factor)
  {
    radius *= factor;
  }

  string str() const override
  {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape
{
  float side;

  Square(){}

  explicit Square(const float side)
    : side{side}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss << "A square with side " << side;
    return oss.str();
  }
};

// we are not changing the base class of existing
// objects

// cannot make, e.g., ColoredSquare, ColoredCircle, etc.

struct ColoredShape : Shape
{
  Shape& shape;
  string color;

  ColoredShape(Shape& shape, const string& color)
    : shape{shape},
      color{color}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape
{
  Shape& shape;
  uint8_t transparency;


  TransparentShape(Shape& shape, const uint8_t transparency)
    : shape{shape},
      transparency{transparency}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has "
      << static_cast<float>(transparency) / 255.f*100.f
      << "% transparency";
    return oss.str();
  }
};

int main()
{
  Square square{5};
  ColoredShape red_square{square, "red"};
  cout << square.str() << endl << red_square.str() << endl;

  TransparentShape transparent_red_square{red_square,10};
  cout << transparent_red_square.str() << endl;

  // Both decorators refer to the same circle. Resizing it updates
  // their descriptions without rebuilding the decorator chain.
  Circle circle{2};
  ColoredShape blue_circle{circle, "blue"};
  TransparentShape transparent_blue_circle{blue_circle, 64};
  cout << "Before resize: " << transparent_blue_circle.str() << endl;
  circle.resize(2);
  cout << "After resize:  " << transparent_blue_circle.str() << endl;
  return 0;
}
