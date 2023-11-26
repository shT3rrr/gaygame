#include <stdexcept>
#include "PlayerManager.h"

PlayerManager::PlayerManager(Player& new_player, Field& new_field):
        player(new_player),
        field(new_field){
}

void PlayerManager::change_vector(Vector new_player_position) {
    if (new_player_position.x >= field.get_heigth() || new_player_position.y >= field.get_width()) {
        throw new std::invalid_argument("passed parameters must be less than field parameters");
    }

    Cell& current_cell = this->field.get_cell_for_index(new_player_position);
    if (current_cell.get_is_passable()){
        player.set_position(new_player_position);
        IGameEvent* cur_gameEvent = current_cell.get_gameEvent();

        if (cur_gameEvent != nullptr){
            bool is_del = cur_gameEvent ->game_event(player);
            if (is_del) {
                current_cell.set_gameEvent(nullptr);
            }
        }
    }

}

void PlayerManager::change_health(int new_health) {
        player.set_health(new_health);
}

void PlayerManager::change_score(int new_score) {
        player.set_score(new_score);
}

Player &PlayerManager::get_player() {
    return player;
}
