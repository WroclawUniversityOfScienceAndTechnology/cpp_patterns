# State
## OVERVIEW:
A pattern in which the object's behavior is determined by its state. An object transistions from one state to another (something needs to trigger a transition).

AA formalized construct which manages state and transitions is callsed a state machine.

## WHEN TO USE:
- Consider an ordinary telephone
- What you do with it depends on the state of the phone/line
  - If it's ringing or you want to make call, you can pick it up
  - Phone must be off the hook to talk/mak a call
  - If you try calling someone, and it's busy, you put the handset down
- Changes in state can be explicit or in response to event (observer pattern)

## SUMMARY:
- Given sufficient complexity, it pays to formally define possible states and events/triggers
- Can define:
  - State entry/exit behaviors
  - Action when a particular event causes a transition
  - Guard considitions enabling/disabling a transition
  - Default action when no transitions are found for an event