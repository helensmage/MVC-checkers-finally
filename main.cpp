#include "store/GameStatusStore.h"
#include "store/GameStatusStore.cpp"
#include "ui/MainScreen/MainScreenModel.h"
#include "ui/MainScreen/MainScreenModel.cpp"
#include "ui/MainScreen/MainScreenView.h"
#include "ui/MainScreen/MainScreenView.cpp"
#include "ui/Cell/CellView.h"
#include "ui/MainScreen/MainScreenController.h"
#include "ui/MainScreen/MainScreenController.cpp"
#include "ui/Board/BoardView.cpp"
#include "ui/Board/BoardModel.cpp"
#include "ui/Cell/CellView.cpp"
#include "ui/Cell/CellModel.cpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include "windows.h"

int main() {
  GameStatusStore store;
  MainScreenModel model(&store);
  MainScreenView view(&model);
  MainScreenController controller(&model);
  while (model.GetWinner() == GameStatusStore::Player::NONE) {
    double start = clock();
    
    controller.start();
    model.notifyUpdate();
    view.draw();

    BoardModel::MoveResult moveResult(BoardModel::MoveResult::PROHIBITED);
    bool direction = model.GetDirection();
    if (model.CheckLines()) {
        auto newMove = std::move(model.GetMove());
        moveResult = model.GetBoard().MakeMove(newMove.first, newMove.second, direction);
    }
    if (moveResult == BoardModel::MoveResult::FF) {
        model.ChangeSurrender();
    }
    if (moveResult == BoardModel::MoveResult::SUCCESSFUL_COMBAT) {
        model.UpdateScore();
    }
    if (moveResult == BoardModel::MoveResult::SUCCESSFUL_MOVE) {
        model.SwitchPlayer();
    }

    if (clock() - start < MS_PER_FRAME) {
        Sleep(((double)MS_PER_FRAME + start - clock()));
    }
    model.IncreaseTimes();
  }
  view.draw();
  Sleep(30000);
  return 0;
}
