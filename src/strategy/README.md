# Strategy
## OVERVIEW:
Enables the exact behaviotof the system to be selected either at tun-time (dynamic) or compile-time (static)

Also known as a policy (esp. in the c++ world)

## WHEN TO USE:
- Many algorithms can be decomposed into higher- and lower-level parts
- Making tea can be decomposed into:
  - The process of making a hot baverage (boil water, pour into cup)
  - Tea-specific things (put reabag into water)

## SUMMARY:
- Define an algorithm at a high level 
- Define the interface you expect each strategy to follow
- Provide for either dynami or static composition of strategy in the overal algorithm
