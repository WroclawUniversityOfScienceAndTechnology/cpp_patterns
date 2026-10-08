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

  Address(const Address& address)
    : street{address.street},
      city{address.city},
      suite{address.suite}
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
  
  Contact(const string &name, Address *address): name{name}, address(address)
  {
  }

  Contact(const Contact& other)
    : name{other.name}
    , address{ new Address{*other.address} }
  {
  }

  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << " works at " << *obj.address; // note the star here
  }
};

int main()
{
  Contact john{"John Doe", new Address{"123 East Dr", "London", 123}};
  Contact jane{john};
  jane.name = "Jane Smith";
  jane.address->suite = 103;

  cout << john << endl << jane << endl;
  return 0;
}