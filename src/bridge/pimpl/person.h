#pragma once
#include <string>

class Person
{
  public:
    std::string name;

    class PersonImpl;
    PersonImpl *impl; // bridge - not necessarily inner class, can vary

    Person();
    ~Person();

    void greet();
};
