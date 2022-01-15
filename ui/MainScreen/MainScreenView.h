#pragma once

#include "MainScreenModel.h"
#include "../../store/GameStatusStore.h"
#include "../../common/IObserver.h"
#include "../../common/Observable.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

#define STD_OUTPUT_HANDLE (DWORD)(0xfffffff5)

double fps = 30;
double MS_PER_FRAME = 1000 / fps;

class MainScreenView: public IView
{
public:
   MainScreenView(MainScreenModel* model);
   virtual void draw();
   virtual void onUpdate(Observable* o);

private:
   MainScreenModel* _model;
};
