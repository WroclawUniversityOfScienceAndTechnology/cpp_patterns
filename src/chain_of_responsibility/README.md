# Chain of responsibility
## OVERVIEW:
A chain of components who all get a change to process a command or a query, optionally having default processing implementation and an ability to terminate the processing chain

## WHEN TO USE:
- You clink a graphical element on a form
  - Button handles it, stops furter processing
  - Underlaying group box 
  - underlaying window
- CCG computer game 
  - Creature has attack and defence values
  - Those can be boosted by other cards (optionally/temporarily)

## SUMMARY:
- Determine the API you have and the API you need 
- Create a component which aggregates (has a reference to, ...) the adaptee
- Intermidiate representations can pile up: use caching and other optimizations