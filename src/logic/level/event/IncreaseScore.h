#ifndef LB3_INCREASESCORE_H
#define LB3_INCREASESCORE_H


#include "IGameEvent.h"

class IncreaseScore: public IGameEvent {
public:
    bool game_event(Player& player) override;
};


#endif //LB3_INCREASESCORE_H
