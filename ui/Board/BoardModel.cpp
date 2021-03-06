#include "BoardModel.h"

BoardModel::BoardModel() : mBoardSize(8)
{

}

BoardModel::~BoardModel()
{

}

void BoardModel::ResetMap() {
  for (size_t i = 0; i < mBoardSize; i++) {
    for (size_t j = 0; j < mBoardSize; j++) {
      CellModel::State state(CellModel::State::BLANK);
      
      if (i == 0 && j % 2 != 0) {
        state = CellModel::State::WHITE;
      }
      else if (i == 1 && j % 2 == 0) {
        state = CellModel::State::WHITE;
      }
      else if (i == 2 && j % 2 != 0) {
        state = CellModel::State::WHITE;
      }
      else if (i == 5 && j % 2 == 0) {
        state = CellModel::State::BLACK;
      }
      else if (i == 6 && j % 2 != 0) {
        state = CellModel::State::BLACK;
      }
      else if (i == 7 && j % 2 == 0) {
        state = CellModel::State::BLACK;
      }

      const pos position = pos(i, j);
      CellModel cell = CellModel(state);
      mCells.insert({ std::move(position), std::move(cell) });
    }
  }
}

BoardModel::MoveResult BoardModel::CheckMove(const pos& startPos, const pos& endPos, bool direction) {
  BoardModel::MoveResult result = BoardModel::MoveResult::PROHIBITED;
  const int dY = endPos.first - startPos.first;
  const int dX = endPos.second - startPos.second;
  bool isCombat = false;

  if (dX == 0 && dY == 0 && endPos.first == 0 && endPos.second == 0) {
    result = BoardModel::MoveResult::FF;
  }
  else if (endPos.first >= 0 && endPos.first < mBoardSize && endPos.second >= 0 && endPos.second < mBoardSize) {
    auto targetCellState = mCells.at(endPos).GetState();
    if (targetCellState == CellModel::State::BLANK) {
      if (abs(dX) == 2 && abs(dY) == 2) {
        pos victimPos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2);
        auto victimCellState = mCells.at(victimPos).GetState();
        auto startCellState = mCells.at(startPos).GetState();
        result = targetCellState != victimCellState && startCellState != victimCellState ? BoardModel::MoveResult::SUCCESSFUL_COMBAT : result;
      }
      else if ((abs(dX) == 1 && dY == 1 && direction) || (abs(dX) == 1 && dY == -1 && !direction)) {
        result = BoardModel::MoveResult::SUCCESSFUL_MOVE;
      }
    }
  }

  return result;
}

BoardModel::MoveResult BoardModel::MakeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat) {
  auto moveResult = CheckMove(startPos, endPos, direction);

  switch(moveResult) {
    case BoardModel::MoveResult::SUCCESSFUL_MOVE:
      mCells.at(endPos).SetState(mCells.at(startPos).GetState());
      mCells.at(startPos).SetState(CellModel::State::BLANK);
      break;
    case BoardModel::MoveResult::SUCCESSFUL_COMBAT:
      mCells.at(endPos).SetState(mCells.at(startPos).GetState());
      mCells.at(startPos).SetState(CellModel::State::BLANK);
      mCells.at(pos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2)).SetState(CellModel::State::BLANK);
      break;
  }

  return moveResult;
}

std::map<pos, CellModel>& BoardModel::GetMap() {
  return mCells;
}

void BoardModel::update() {
  notifyUpdate();
}
