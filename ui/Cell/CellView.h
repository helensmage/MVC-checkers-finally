#pragma once

#include "CellModel.h"
#include "../../common/IView.h"
#include "../../common/IObserver.h"
#include "../../common/Observable.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

class CellView: public IView
{
public:
  CellView(CellModel* model);
  virtual void draw();
  virtual void onUpdate(Observable* o);

private:
  CellModel* _model;
};
