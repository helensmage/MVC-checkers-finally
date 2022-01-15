#pragma once

#include "../../common/IModel.h"
#include "../Cell/CellModel.h"
#include "../../store/GameStatusStore.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

class MainScreenModel : public IModel
{
public:
   MainScreenModel(GameStatusStore* model);
   void update();
   BoardModel& GetBoard();
   size_t GetWhiteScore();
   size_t GetBlackScore();
   bool GetSurrender();
   std::string GetCurrentPlayer() const;
   GameStatusStore::Player GetWinner() const;
   bool GetDirection() const;
   std::pair<pos, pos> GetMove();
   void UpdateScore();
   void SwitchPlayer();
   std::string CastPlayer(GameStatusStore::Player player) const;
   void ChangeSurrender();
   void FillLines(char c);
   bool CheckLines();
   std::string GetCurrentLine1() const;
   std::string GetCurrentLine2() const;
   void IncreaseTimes();
   int GetTimes() const;

private:
   GameStatusStore* _model;
};
