# Facade
## OVERVIEW:
Provide a simple, easy to understand/user interface over a large and sophisticated body of code

## WHEN TO USE:
- Balancing complexity and presentation/usability
- Typical home-ish approach:
  - Many subsustems (electrical, sanitation,...)
  - Complex internal structure (e.g. floor layers)
  - End user is not exposed to internals
- Same with software
  - Many systems working to provide flexibility,
  - API consumets want it to 'just work'
  
## SUMMARY:
- Build a Facade to provide a simplified API over a set of classes
- May wish to (optionally) expose internals through the facade
- May allow user to 'escalate' to use more complex APIs if they need to 