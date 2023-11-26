#include "TeleportPlayer.h"


bool TeleportPlayer::game_event(Player &player){
    player.set_position(new_position);
    return false;
}

void TeleportPlayer::set_new_position(Vector position) {
    this->new_position = position;
}
