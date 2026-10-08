# Template Methods
## OVERVIEW:
Allows us to define the "skeleton" of the algorithm, with concrete implementetions defined in subclasses

## WHEN TO USE:
- Algorithms can be decomposed into common parts and specifics 
- Strategy pattern does this through composition 
  - High-level algorithm used an interface
  - Concrete implemenatitos implement the interface
- Template Method does the same thing trough inheritence
  - Overall algorithm makes use of abstract member
  - Inheritors override the abstract member
  - inheritors override the abstract members
  - Parent template method invoked

## SUMMARY:
- Define an algorithm at a high level
- define constituent parts as abstract methods
- Inherit the algorithm class providing necessary overrides