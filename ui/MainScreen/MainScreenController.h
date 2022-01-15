#pragma once

#include "../../common/IController.h"
#include "../../store/GameStatusStore.h"
#include "MainScreenModel.h"
#include "../Cell/CellModel.h"
#include "../Board/BoardModel.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <cmath>
#include <algorithm>

class MainScreenController : public IController
{
public:
  MainScreenController(MainScreenModel* model);
  void start();

private:
  MainScreenModel* _model;
};
