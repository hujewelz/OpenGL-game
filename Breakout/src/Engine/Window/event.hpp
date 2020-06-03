#ifndef EVENT_H
#define EVENT_H

enum Key
{
    kUnknownKey = -1,
    kKey_0 = 0
};

enum EventState
{
    kStateDefault = -1,
    // The key or mouse button was released
    kRelease = 0,
    // The key or mouse button was pressed
    kPress
};

struct Event
{
    Key key;
    EventState state;

    Event(Key key_, EventState state_) : key(key_), state(state_) {}
    Event() : key(kUnknownKey), state(kStateDefault){};
    ~Event() {}
};

typedef void (*EventHandlerFun)(Event event);

struct EventHandler
{
    EventHandler(Event event_, EventHandlerFun handler_) : event(event_), handler(handler_) {}
    EventHandler() : event(kUnknownKey, kStateDefault), handler(nullptr) {}
    ~EventHandler(){};

    Event event;
    EventHandlerFun handler;
};

#endif