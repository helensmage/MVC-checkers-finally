#include "GameStatusStore.h"

GameStatusStore::GameStatusStore() : mWhiteScore(0), mBlackScore(0), mLastPlayer(Player::NONE), bIsSurrender(false), times(0)
{
  mboard.ResetMap();
  v = new BoardView(&mboard);
  line1 = "";
  line2 = "";
}
