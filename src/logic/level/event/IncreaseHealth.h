#ifndef LB3_INCREASEHEALTH_H
#define LB3_INCREASEHEALTH_H

#include "IGameEvent.h"

class IncreaseHealth: public IGameEvent {
public:
    bool game_event(Player& player) override;
};


#endif //LB3_INCREASEHEALTH_H
