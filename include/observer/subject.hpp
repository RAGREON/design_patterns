#pragma once

class IObserver;

class ISubject {
public:
  virtual void add_observer(IObserver &o) = 0;
  virtual void remove_observer(IObserver &o) = 0;
  virtual void notify_observers() = 0;
  virtual ~ISubject() {}
};

