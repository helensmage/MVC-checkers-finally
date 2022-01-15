#pragma once

#include "../ui/Board/BoardModel.h"
#include "../ui/Board/BoardView.h"

class GameStatusStore
{
public:
  GameStatusStore();
  enum class Player { NONE, BLACK, WHITE };
  bool bIsSurrender;
  BoardModel mboard;
  BoardView* v;
  size_t mWhiteScore;
  size_t mBlackScore;
  Player mLastPlayer;
  std::string line1;
  std::string line2;
  int times;
};
