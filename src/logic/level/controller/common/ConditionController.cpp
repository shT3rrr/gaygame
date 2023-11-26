//
// Created by Илья on 06.11.2023.
//

#include <iostream>
#include "ConditionController.h"

LevelResult ConditionController::check_conditions(Field *field, Player &player) {
    if (player.get_position().x == field->get_finish().x &&
        player.get_position().y == field->get_finish().y) {
        std::cout << "Yay, you won" << std::endl;
        return LevelResult::CHOOSE_NEW_LEVEL;
    }
    if (player.get_health() == 0) {
        std::cout << "Haha, you died" << std::endl;
        return LevelResult::CHOOSE_NEW_LEVEL;
    }
    if (player.get_position().x == field->get_finish().x &&
        player.get_position().y == field->get_finish().y && player.get_score() == 1000) {
        std::cout << "Wow, you are cool!" << std::endl;
        return LevelResult::CHOOSE_NEW_LEVEL;
    }
    return LevelResult::null;
}
