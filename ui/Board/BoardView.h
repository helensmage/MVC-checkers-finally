#pragma once

#include "BoardModel.h"
#include "../../common/IView.h"
#include "../../ui/Cell/CellView.h"
#include "../../common/IObserver.h"
#include "../../common/Observable.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

using pos = std::pair<std::size_t, std::size_t>;

class BoardView: public IView
{
public:
  BoardView(BoardModel* model);
  virtual void draw();
  virtual void onUpdate(Observable* o);

private:
  BoardModel* _model;
};
