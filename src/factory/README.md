# Factory
## OVERVIEW:
A component responsible solely for the wholesale (not piecewise) creation of obcjects.

## WHEN TO USE:
- When Ocject creation logic become too convoluted
- Constructor is not descriptive
  - Name mandated by name of containing type
  - Cannon overload with same sets of arguments with diffrent names
  - Can turn into 'optional paramenter hell'
- Object creation (non-piecewise, unlike Builder pattern) can be outsourced to:
  - A separate function (Factory Method)
  - That may exist in a separete class (Factory)
  - Can create hierarchy of factories with Absctract Factory

## SUMMARY:
- A factory method is a static method that creates objects
- A factory can take care of object creation
- A factory can be external or reside inside the object as an inner class
- Hierarchies of factories can be used to create releted objects