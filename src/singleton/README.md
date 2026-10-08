# Singleton
## OVERVIEW:
A component which is instantiated only once

## WHEN TO USE:
- For some components it only makes sense to have one in the system
  - Daatabase repository
  - object factory
- e.g. the constructor call is expensive
  - we only do it once
  - we provice everyone with the same instance
- Want to prevent anyone creating additional copies
- Need to take case of lazy instantiation and thread safety

## SUMMARY:
- Making a 'safe' singleton is easy:
  - hide or delete type's constructor, copy constructor and copy assignment operator
  - create a static method that returns a reference to a static member
  - guaranteed to be thread-safe since C++11
- Type with 'hard' dependencies on singletons are difficult to test
  - Cannot decouple the singleton and supply a fake object
- Instead of directly using singleton, consider depending on an abstraction (e.g. and interface)
- Consider defining singleton lifetime in DI containter 