# Visitor
## OVERVIEW:
A pattern where a component (visitor) is allowed to traverds the entire inheritance hierarchy. Implemented by propagating a single visit() method throughout the entire hierarchy.

## WHEN TO USE:
- Need to define a new operation on an entire class hierarchy
  - e.g. make a document model printable on HTML/Markdown
- Do not want to keep modifying every class in the hierarchy
- Need access to the non-common aspects of classes in the hierarchy
  - Cannot put everything into a single interface
- Create an external component to handle rendering
  - But prefarably avoid the checks

## SUMMARY:
- Propagate an accpets(Visitor* v) method throughout the entire hierarchy
- Create a visitor with visit(Foo*), visit(Bar* ), ... for each element in the hierarchy
- Each accept() simply calls visitor.visit(this)
