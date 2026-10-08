# Prototype
## OVERVIEW:
A partially or fully initialized object that you copy (clone) and make use of.

## WHEN TO USE:
- Complicated obcjects (e.g. car) aren't design from scratch"
  - They reiterate existing designs
- An existing (partially or fully constructed) design is a Prototype
- We make a copy (clone) the prototype and customize it 
  - Requires 'deep copy' support
- We make the cloning convenient (e.g. via Factory) 

## SUMMARY:
- To implement a prototype, partially construct an object and store it somewhere
- Clone the prototype:
  - Implement your own deep copy functionality; or
  - Serialize and deserialize
- Customize the resulting instance