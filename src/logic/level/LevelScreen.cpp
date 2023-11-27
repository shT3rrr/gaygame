//
// Created by Илья on 05.11.2023.
//

#include <iostream>
#include "LevelScreen.h"
#include "src/logic/level/field/Field.h"
#include "CreateLevel.h"
#include "src/logic/level/entity/PlayerManager.h"
#include "src/logic/level/controller/common/IControllerFactory.h"

LevelResult LevelScreen::run(int level_number) {
    Field *level = CreateLevel::instance().create_level(level_number);
    Vector start = level->get_start();
    Player player(100, 0, start);

    PlayerManager pm(player, *level);

    render_controller->setup();
    //render_controller->render(level, player);
    LevelResult result = LevelResult::null;
    while (true) {
        render_controller->render(level, player);

        Command command = input_controller->get_command(dict);

        //} while (command == Command::null);
        result = command_controller->process_command(pm, command);
        if (result != LevelResult::null) {
            break;
        }
        result = condition_controller->check_conditions(level, player);
        if (result != LevelResult::null) {
            break;
        }
    }

    while (true) {
        if (render_controller->renderGameOver(level, player)) {
            break;
        }
    }
    render_controller->close();
    return result;
}

LevelScreen::LevelScreen(const std::map<char, Command> &dict, IControllerFactory &controllerFactory)
        : dict(dict),
          input_controller(controllerFactory.inputController()),
          render_controller(controllerFactory.renderController()),
          command_controller(controllerFactory.commandController()),
          condition_controller(controllerFactory.conditionController()) {};
