#pragma once

class IDisplayElement {
public:
  virtual void display() = 0;
  virtual ~IDisplayElement() {}
};
