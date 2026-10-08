#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>

using namespace std;

struct Address
{
  string street;
  string city;
  int suite;


  Address(const string& street, const string& city, const int suite)
    : street{street},
      city{city},
      suite{suite}
  {
  }

  Address(const Address& other)
    : street{other.street},
      city{other.city},
      suite{other.suite}
  {
  }

  friend ostream& operator<<(ostream& os, const Address& obj)
  {
    return os
      << "street: " << obj.street
      << " city: " << obj.city
      << " suite: " << obj.suite;
  }
};


struct Contact
{
  string name;
  Address* address;

  Contact& operator=(const Contact& other)
  {
    if (this == &other)
      return *this;
    name = other.name;
    address = other.address;
    return *this;
  }

  Contact(string name, Address* address)
    : name{name}, address{address}
  {
  }

  Contact(const Contact& other)
    : name{other.name}
  {
    address = new Address(
      other.address->street, 
      other.address->city, 
      other.address->suite
    );
  }

  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << " works at " << *obj.address; // note the star here
  }
};

struct EmployeeFactory
{
  static Contact main;
  static Contact aux;

  static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
  {
    return NewEmployee(name, suite, main);
  }

  static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite)
  {
    return NewEmployee(name, suite, aux);
  }

private:
  static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
  {
    auto result = make_unique<Contact>(proto);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

Contact EmployeeFactory::main{ "", new Address{ "123 East Dr", "London", 0 } };
Contact EmployeeFactory::aux{ "", new Address{ "123B East Dr", "London", 0 } };

int main()
{
  auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
  auto jane = EmployeeFactory::NewAuxOfficeEmployee("Jane Doe", 125);

  // note the stars here as we are using smart pointers
  cout << *john << "\n" << *jane << "\n"; 

  getchar();
  return 0;
}