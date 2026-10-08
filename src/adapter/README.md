# Adapter
## OVERVIEW:
A construct which adapts an existing interface X to conform to the required interface Y

## WHEN TO USE:
- We cannot modify our gadgets to support every possible interface (like e.g. for wall plug where we have EU, UK, USA...)

## SUMMARY:
- Determine the API you have and the API you need 
- Create a component which aggregates (has a reference to, ...) the adaptee
- Intermidiate representations can pile up: use caching and other optimizations