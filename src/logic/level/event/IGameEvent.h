#ifndef LB3_IGAMEEVENT_H
#define LB3_IGAMEEVENT_H

#include "src/logic/level/entity/Player.h"

class IGameEvent{
public:
    virtual bool game_event(Player& player) = 0;
};


#endif //LB3_IGAMEEVENT_H
