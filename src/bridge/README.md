# Bridge
## OVERVIEW:
A mechanism that decouples an interface (hierarchy) from an implementations (hierarchy)

## WHEN TO USE:
- Bridge prevent a 'Cartesion product' complexity explosion
  - Base class TreadScheduler
  - Can be preemptive or cooperative
  - Can run Windows or Unix
  - help to avoid ends up with a 2x2 scenario: WindowsPTS, UnixPTS, WindowsCTS, UnixCTS
  - Bridge patter avoids the entity explosion

## SUMMARY:
- Decouple abstraction from implementation
- Both can exist an hierarchies
- A stronger form of encapsulation