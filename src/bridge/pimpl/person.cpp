#include "person.h"
#include <iostream>

struct Person::PersonImpl
{
  public:
    void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
  std::cout << "hello" << p->name << std::endl;
}

Person::Person()
  : impl(new PersonImpl)
{
}

Person::~Person()
{
  delete impl;
}

void Person::greet()
{
  impl->greet(this);
}


