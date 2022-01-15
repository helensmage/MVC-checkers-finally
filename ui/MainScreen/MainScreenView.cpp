#include "MainScreenView.h"

MainScreenView::MainScreenView(MainScreenModel* model) : _model(model)
{
  _model->addObserver(this);
}

void MainScreenView::draw() {
  if (_model->GetSurrender()) {
      std::cout << std::endl << "Game Over!" << std::endl;
      std::cout << _model->CastPlayer(_model->GetWinner()) << " wins!" << std::endl;
  }
  else {
      COORD coord = {0, 0};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

      std::cout << "White Player score: " << _model->GetWhiteScore() << "                             ";

      std::cout << "| " << std::setw(2) << static_cast<int>(MS_PER_FRAME * _model->GetTimes() / 1000 / 60) << "m : " <<
      std::setw(2) << static_cast<int>(MS_PER_FRAME * _model->GetTimes() / 1000) % 60 << "s : " <<
      std::setw(2) << ((static_cast<int>(MS_PER_FRAME * _model->GetTimes()) < 1000) ? static_cast<int>(MS_PER_FRAME) * _model->GetTimes()
      : static_cast<int>(MS_PER_FRAME) * _model->GetTimes() % 1000) << "ms |" << std::endl;

      std::cout << "Black Player score: " << _model->GetBlackScore() << std::endl << std::endl;
        
      BoardView view(&_model->GetBoard());
      view.draw();
        
      std::cout << _model->GetCurrentPlayer() << " move:" << std::endl;

      std::cout << _model->GetCurrentLine1() << _model->GetCurrentLine2() << "    " << std::endl;
  }
}

void MainScreenView::onUpdate(Observable* o) {
  _model = static_cast<MainScreenModel*>(o);
}
