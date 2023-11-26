#ifndef LB3_REDUCEHEALTH_H
#define LB3_REDUCEHEALTH_H


#include "IGameEvent.h"

class ReduceHealth: public IGameEvent {
public:
    bool game_event(Player& player) override;
};


#endif //LB3_REDUCEHEALTH_H
