#include "ReduceHealth.h"

bool ReduceHealth::game_event(Player &player) {
    int health = player.get_health();
    if (health - 25 < 0){
        health = 0;
    }
    else{
        health -= 25;
    }
    player.set_health(health);
}