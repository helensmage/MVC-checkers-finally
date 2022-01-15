#include "CellModel.h"

CellModel::CellModel(State state) : mState(state) 
{

}

std::string CellModel::CastState() {
  std::string result;
  switch(mState) {
    case State::BLACK:
      result = "B";
      break;
    case State::WHITE:
      result = "W";
      break;
    default:
      result = " ";
      break;
  }
  return std::move(result);
}

CellModel::State CellModel::GetState() const {
  return mState;
}

void CellModel::SetState(State state) {
  mState = state;
}

void CellModel::update() {
  notifyUpdate();
}
