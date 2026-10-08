# Mediator
## OVERVIEW:
A component that facilitates communication between other components without them necessarily being aware of each other or having direct (reference) access to each other 

## WHEN TO USE:
- Components may go in a nd out of the system at any time 
  - Chat room participants
  - Players in an MMORPG
- It makes no sense for them to have direct references to one another 
  - Those references may go dead
- Solution: have than all refer to some central component that facilitates communication 

## SUMMARY:
- Create the mediator and have each object in the system refer to it e.g. in a field
- Mediator engages in bidirectional communication with its connected components
- Mediator has functions the mediator can call 
- Event processing (e.g. Rx) libraries make communication easier to implement 