#pragma once

#include "../../common/IModel.h"

#include <utility>
#include <string>

using pos = std::pair<std::size_t, std::size_t>;

class CellModel : public IModel
{
public:
  enum class State {BLACK, WHITE, BLANK};
  CellModel(State state);
  State GetState() const;
  void SetState(State state);
  std::string CastState();
  void update();

private:
  State mState;
};
