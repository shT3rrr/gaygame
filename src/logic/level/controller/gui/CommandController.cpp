#include <iostream>
#include "CommandController.h"
#include "src/logic/level/LevelResultEnum.h"

LevelResult CommandController::process_command(
        PlayerManager &pm, Command command) {
    Vector start = pm.get_player().get_position();
    switch (command) {
        case Command::DOWN: {
            start.x += 1;
            pm.change_vector(start);
            break;
        }
        case Command::UP: {
            start.x -= 1;
            pm.change_vector(start);
            break;
        }
        case Command::RIGHT: {
            start.y += 1;
            pm.change_vector(start);
            break;
        }
        case Command::LEFT: {
            start.y -= 1;
            pm.change_vector(start);
            break;
        }
        case Command::BACK: {
            return LevelResult::CHOOSE_NEW_LEVEL;
        }
        case Command::QUIT: {
            std::cout << "Do you want to leave?? Uh, okay." << std::endl;
            return LevelResult::EXIT;
        }
        default: {
            break;
        }
    }
    return LevelResult::null;

}

