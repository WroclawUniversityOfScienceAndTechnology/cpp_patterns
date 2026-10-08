# Memento
## OVERVIEW:
A token/handle representing the system state. Lets us roll back to the state when the token was generated. May or may not directly expose state information.

## WHEN TO USE:
- An object or system goes through changes, e.g. a bank account gets deposits and withdrwals 
- There are different way of navigating those changes
- One way is to record every change (Command) and teach a command to 'undo' itself
- Another is to simply save snapshots of the system

## SUMMARY:
- Mementos are used to roll vack states 
- A memento is simply a token/handle class with (typically) no functions of its own
- A memento is not required to expose directly the state(s) to which it reverts the system 
- Can be used to implement undo/redo