#pragma once

#include "../Cell/CellModel.h"
#include "../../common/IModel.h"
#include "../../ui/Cell/CellView.h"

#include <map>

class BoardModel : public IModel
{
public:
  enum class MoveResult { SUCCESSFUL_MOVE, SUCCESSFUL_COMBAT, PROHIBITED, FF };
  BoardModel();
  ~BoardModel();
  void ResetMap();
  MoveResult MakeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat = false);
  std::map<pos, CellModel>& GetMap();
  void update();

private:
  MoveResult CheckMove(const pos& startPos, const pos& endPos, bool direction);
  const size_t mBoardSize;
  std::map<pos, CellModel> mCells;
};
