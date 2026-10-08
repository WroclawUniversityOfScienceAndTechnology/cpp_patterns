#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
using namespace boost;

struct Address
{
  string street;
  string city;
  int suite;
  
  Address()
  {
  }

  Address(const string& street, const string& city, const int suite)
    : street{street},
      city{city},
      suite{suite}
  {
  }

private:
  friend class boost::serialization::access;

  template <class archive>
  void serialize(archive& ar, const unsigned version)
  {
    ar & street;
    ar & city;
    ar & suite;
  }

  // You can split serialization
  // template <class archive>
  // void save(archive& ar, const unsigned version) const
  // {
  //   ar << street;
  //   ar << city;
  //   ar << suite;
  // }
  // template <class archive>
  // void load(archive& ar, const unsigned version)
  // {
  //   ar >> street;
  //   ar >> city;
  //   ar >> suite;
  // }
  // BOOST_SERIALIZATION_SPLIT_MEMBER()

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

  Contact()
  {} // required for serialization

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

private:
  friend class boost::serialization::access;

  template <class archive>
  void serialize(archive& ar, const unsigned version) 
  {
    ar & name;
    ar & address;
  }

  // You can split serialization
  // template <class archive>
  // void save(archive& ar, const unsigned version) const
  // {
  //   ar << name;
  //   ar << address;
  // }
  // template <class archive>
  // void load(archive& ar, const unsigned version)
  // {
  //   ar >> name;
  //   ar >> address;
  // }
  // BOOST_SERIALIZATION_SPLIT_MEMBER()

public:
  ~Contact()
  {
    delete address;
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
  auto clone = [](const Contact& c)
  {
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << c;
    string s = oss.str();
    cout << "serialization!!!!!!\n" 
         << s 
         << "\nserialization!!!!!!" << endl;

    istringstream iss(s);
    boost::archive::text_iarchive ia{iss};
    Contact result;
    ia >> result;
    return result;
  };

  auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
  auto jane = clone(*john);
  jane.name = "Jane Doe";

  cout << *john << "\n" << jane << "\n"; 

  return 0;
}