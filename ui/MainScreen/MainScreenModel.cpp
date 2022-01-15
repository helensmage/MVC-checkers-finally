#include "MainScreenModel.h"

MainScreenModel::MainScreenModel(GameStatusStore* model) : _model(model)
{

}

void MainScreenModel::update() {
  notifyUpdate();
}

BoardModel& MainScreenModel::GetBoard() {
  return _model->mboard;
}

size_t MainScreenModel::GetWhiteScore() {
  return _model->mWhiteScore;
}

size_t MainScreenModel::GetBlackScore() {
  return _model->mBlackScore;
}

bool MainScreenModel::GetSurrender() {
  return _model->bIsSurrender;
}

std::string MainScreenModel::GetCurrentPlayer() const {
  std::string player;
  if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
    player = "Black";
  }
  else {
    player = "White";
  }
  return std::move(player);
}

GameStatusStore::Player MainScreenModel::GetWinner() const {
  GameStatusStore::Player winner(GameStatusStore::Player::NONE);
    if (_model->bIsSurrender) {
      if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
        winner = GameStatusStore::Player::BLACK;
      }
      else if (_model->mLastPlayer == GameStatusStore::Player::BLACK) {
        winner = GameStatusStore::Player::WHITE;
      }
    }
    else {
      if (_model->mWhiteScore == 12) {
        winner = GameStatusStore::Player::WHITE;
    }
    else if (_model->mBlackScore == 12) {
        winner = GameStatusStore::Player::BLACK;
    }
  }
  return winner;
}

bool MainScreenModel::GetDirection() const {
  bool direction;
  switch(_model->mLastPlayer) {
    case GameStatusStore::Player::WHITE:
    direction = false;
    break;
    default:
    direction = true;
    break;
  }
  return direction;
}

std::pair<pos, pos> MainScreenModel::GetMove() {
  std::pair<pos, pos> position;
  size_t p1, p2;
  bool isLine1Number = true, isLine2Number = true;
  std::for_each(_model->line1.cbegin(), _model->line1.cend(), [&](char c) { if (!isdigit(c)) isLine1Number = false; });
  std::for_each(_model->line2.cbegin(), _model->line2.cend(), [&](char c) { if (!isdigit(c)) isLine2Number = false; });
  if (!isLine1Number || !isLine2Number) {
    if (_model->line1 == "ff") {
      position.first.first = 0;
      position.first.second = 0;
      position.second.first = 0;
      position.second.second = 0;
    }
    else {
      position.first.first = 1;
      position.first.second = 1;
      position.second.first = 1;
      position.second.second = 1;
    }
  }
  else {
    p1 = static_cast<size_t>(std::stoi(_model->line1));
    p2 = static_cast<size_t>(std::stoi(_model->line2));
    position.first.first = p1 / 10;
    position.first.second = p1 - 10 * position.first.first;
    position.second.first = p2 / 10;
    position.second.second = p2 - 10 * position.second.first;
  }
  _model->line1 = "";
  _model->line2 = "";
  return std::move(position);
}

void MainScreenModel::UpdateScore() {
  if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
    _model->mBlackScore++;
  }
  else {
    _model->mWhiteScore++;
  }
}

void MainScreenModel::SwitchPlayer() {
  if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
    _model->mLastPlayer = GameStatusStore::Player::BLACK;
  }
  else {
    _model->mLastPlayer = GameStatusStore::Player::WHITE;
  }
}

std::string MainScreenModel::CastPlayer(GameStatusStore::Player player) const {
  std::string playerStr;
    switch (player) {
      case GameStatusStore::Player::WHITE:
      playerStr = "White player";
      break;
      default:
      playerStr = "Black player";
      break;
    }
    return playerStr;
}

void MainScreenModel::ChangeSurrender() {
  _model->bIsSurrender = true;
  if (_model->mWhiteScore >= _model->mBlackScore) {
      GameStatusStore::Player::WHITE;
  }
  else {
      GameStatusStore::Player::BLACK;
  }
}

void MainScreenModel::FillLines(char c) {
  if (_model->line1.size() < 2) {
    _model->line1 += c;
  }
  else if (_model->line2.size() < 2) {
   _model->line2 += c;
  }
}

bool MainScreenModel::CheckLines() {
  if (_model->line1.size() == 2 && _model->line2.size() == 2) {
    return true;
  }
  return false;
}

std::string MainScreenModel::GetCurrentLine1() const {
  return _model->line1;
}

std::string MainScreenModel::GetCurrentLine2() const {
  return _model->line2;
}

void MainScreenModel::IncreaseTimes() {
  _model->times++;
}

int MainScreenModel::GetTimes() const {
  return _model->times;
}
