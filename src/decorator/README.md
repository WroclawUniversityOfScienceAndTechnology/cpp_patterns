# Decorator
## OVERVIEW:
Facitilates the addition of behaviours to individial objects.

## WHEN TO USE:
- Want to augment an object with additinal functionality
- Do not want to rewrite or alter existing code (OCP)
- Want to keep new functionaluty separate (SRP)
- Need to be able to interact with existing structures
- Two options 
  - Aggregate the decorated object
  - Inherit from the decorated object
  
## SUMMARY:
- A dynamic decorator keeps the reference to the deorated object(s)
  - ColeredShapre{Square{}}
- A static decorator uses mixin inheritance
  - ColeredShapre<Square>
- Both approaches alow limitless composition
  - TransparentShape<ColoredShape<Circle>>
