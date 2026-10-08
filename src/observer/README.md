# Observer
## OVERVIEW:
An observer is an object that wishes to be informed about events happening in the system. The entity generating the events is an observable.

## WHEN TO USE:
- We need to be informed when certain things happen
  - Object's field changes
  - Object does something
  - Some external event occurs
- We want to listen to events and notify when they occur
- Terminology:
  - event (publisher) and subscriber
  - signal and slot (Boost, Qt, etc.)

## SUMMARY:
- Two partipants:
  - Observable privides a way of subscribing to an event (signal)
  - Observer perform the subscription
- Observable implementation is always intrusive (observer doesn't need to be)
- Multithreaded/reentrant use can cause issuses
- Ready-made implementations of Observer are available