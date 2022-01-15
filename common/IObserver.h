#pragma once

#include "Observable.h"

class Observable;

class IObserver
{
public:
  virtual void draw() = 0;
  virtual void onUpdate(Observable* o) = 0;
};
