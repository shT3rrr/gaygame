#ifndef LB3_PLAYERMANAGER_H
#define LB3_PLAYERMANAGER_H

#include "src/logic/level/entity/Player.h"
#include "src/logic/level/field/Field.h"
#include "src/logic/level/field/Cell.h"

class PlayerManager {
public:
    PlayerManager(Player& new_player, Field& field);
    void change_vector(Vector new_player_position);
    void change_health(int new_health);
    void change_score(int new_score);
    Player& get_player();

private:
    Player& player;
    Field& field;
};

#endif
