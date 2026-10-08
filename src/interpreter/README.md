# Interpreter
## OVERVIEW:
A component that processes structured text data. Does so by turning it into separate lexical tokens (lexing) and then interpeting sequences of said tokens (parsing).

## WHEN TO USE:
- Textual input needs to be precessed
  - eg. turned into OOP structurs
- Some examples:
  - Programming languages compilers interpretes and IDEs
  - HTML, XML and similar
  - Numeric expressions using tokens (3+4/5)
  - Regular expressions
- Turning string into OOP based structures in a complicated process

## SUMMARY:
- Barring simples cases, an interpreter acts in to stages
- Lexing turns text into a set of tokens e.g. 3*4 -> Lit[3] star Lparen Lit[4] Plus Lit[5] Rparen
- Parsing tokens into meaningful constructs
- Parsed data can then be traversed
