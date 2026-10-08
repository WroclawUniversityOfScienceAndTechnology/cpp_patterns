# Composite
## OVERVIEW:
A mechanism for treating individial (scalar) objects and compositions of objects in a uniform manner

## WHEN TO USE:
- Objects use other objects fileds/properties/members througgh inheritannce and composition
- Composition lets us make compounds objects 
  - e.g. a mathematical expression composed of siple expressions
  - a grouping of shapes that consists of several shapes
  - nested menu
- Composite design pattern is used to treat botu single (scalar) and composite object uniformly
  - i.e. Foo and Collection<Foo> have common API
  
## SUMMARY:
- Objects can use other objects via inheritance/composition
- Some composed and singular objects need similar/identical behaviors
- Composite designe pattern letes us threat both types of objects uniformly
- C++ uses duck typing, expecting enumerable tyles to provide begin()/end()
- A single object can masquerade as a collection
  - Foo* begin{} {return this;}
  - Foo* end{} { return this+1;}