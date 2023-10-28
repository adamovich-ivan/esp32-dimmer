#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H

#include <vector>
#include <algorithm>

// Observer Interface
class Observer {
public:
  virtual void update(int brightness) = 0;
};

// Subject Interface
class Subject {
public:
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObservers() = 0;
};

#endif // OBSERVER_PATTERN_H
