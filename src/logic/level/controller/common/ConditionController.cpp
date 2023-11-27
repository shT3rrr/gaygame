//
// Created by Илья on 06.11.2023.
//

#include <iostream>
#include "ConditionController.h"

LevelResult ConditionController::check_conditions(Field *field, Player &player) {
    if (player.get_position().x == field->get_finish().x &&
        player.get_position().y == field->get_finish().y) {
        return LevelResult::CHOOSE_NEW_LEVEL;
    }
    if (player.get_health() == 0) {
        return LevelResult::CHOOSE_NEW_LEVEL;
    }
    return LevelResult::null;
}
