# Builder
## OVERVIEW:
When piecewise object construction is complicated provide an API for doing it succinctly.

## WHEN TO USE:
- for object which have complicated construction e.g. few steps are needed
- when having an object with lot of constructor arguments 
- instad, opt for piecewise construction
- when object need to be construct step-by-step

## SUMMARY:
- A builder is a separate component for building an object 
- Can either ive builder constructor or return it via a static function
- To make builder fluent, return <b>*this</b>
- Diffrent facets of an object can be build with diffrent builders working in a tandem via base class 