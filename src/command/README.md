# Command
## OVERVIEW:
An object which represents an instruction to perform a particular action. Contains all the information necessary for the action to be taken.

## WHEN TO USE:
- Ordinary c++ statements are perishable
  - Cannot undu a filed/property assignment
  - Cannot direclty serialize a sequence of actions (calls)
- Want an object that represent an operation
  - X should change its field Y to the value Z
  - X should do W()
- Uses: GUI commands, multi-level undo/redo, macro recording and mode!
- Command = asking for an action or change (e.g. please set your attack value to 2)
- Query = asking for information (e.g. please give me your attack value)
- CQS = having separate means of sending commands and queries

## SUMMARY:
- Encapsulate all details of an operation in a separate object
- Define instruction for applying the command (either in the command itself, or elsewhere)
- Optionally define instructions for undoing the command
- Can create composite command (aka macros)