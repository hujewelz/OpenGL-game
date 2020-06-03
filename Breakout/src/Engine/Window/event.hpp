#ifndef EVENT_H
#define EVENT_H

enum Key
{
    Key_0 = 0
};

enum EventState
{
    // The key or mouse button was released
    Release = 0,
    // The key or mouse button was pressed
    Press
};

typedef void (*EventHandlerFun)(Event &event);

struct Event
{
    Key key;
    EventState state;

    Event(Key key_, EventState state_) : key(key_), state(state_) {}
    Event(){};
};

class EventHandler
{
public:
    EventHandler(Event event, EventHandlerFun handler_);
    ~EventHandler();

    Event GetEvent() { return event_; }
    EventHandlerFun Handler() { return handler_; }

private:
    Event event_;
    EventHandlerFun handler_;
};

#endif