#include "IncreaseHealth.h"

bool IncreaseHealth::game_event(Player& player) {
    int health = player.get_health();
    if (health + 25 > 100){
        health = 100;
    }
    else{
        health += 25;
    }
    player.set_health(health);
    return true;
}
