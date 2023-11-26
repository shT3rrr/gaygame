#ifndef LB3_TELEPORTPLAYER_H
#define LB3_TELEPORTPLAYER_H


#include "IGameEvent.h"

class TeleportPlayer: public IGameEvent {
private:
    Vector new_position;
public:
    void set_new_position(Vector position);

    bool game_event(Player& player) override;
};


#endif //LB3_TELEPORTPLAYER_H