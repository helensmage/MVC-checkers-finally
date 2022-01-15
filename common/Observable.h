#pragma once

#include "IView.h"
#include "IObserver.h"

#include <vector>

class Observable
{
public:
  void addObserver(IObserver* observer);
  void notifyUpdate();

private:
  std::vector<IObserver*> _observers;
};
