# Proxy
## OVERVIEW:
A class that functions as an interface to a particular resource. This resource may be remote, exponsive to construct, or may require loggin or some other added functionality.

## WHEN TO USE:
- You are calling foo bar()
- This assumes that foo is in the same process as bar()
- What if, later on, you want to put all Foo-related operations into a separate process, and avoid changing your code?
- Proxy deliver same interface, and entirely different different behavior
- This is called a communication proty 
  - other types: loggin, virtual, guarding 

## SUMMARY:
- A proxy has the same interface as the underlaing object
- To create a proxy, simply replicate the existign interface of an object
- Add relevant functionality to the redefined member functions
- Different proxies (communication, loggin, caching, etc.) have completely different behaviors