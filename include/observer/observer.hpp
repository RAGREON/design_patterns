#pragma once

class ISubject;

class IObserver {
public:
  virtual void update() = 0;
  virtual void subscribe(ISubject &o) = 0;
  virtual void unsubscribe() = 0;
  virtual ~IObserver() {}
};
