//
// Created by Илья on 05.11.2023.
//

#include <iostream>
#include "LevelScreen.h"
#include "src/logic/level/field/Field.h"
#include "CreateLevel.h"
#include "src/logic/level/entity/PlayerManager.h"
#include "src/logic/level/controller/gui/InputController.h"
#include "src/logic/level/controller/gui/CommandController.h"
#include "src/logic/level/controller/gui/RenderController.h"
#include "src/logic/level/controller/gui/ConditionController.h"
#include "src/logic/level/controller/IRenderController.h"

LevelResult LevelScreen::run(int level_number) {
    Field *level = CreateLevel::instance().create_level(level_number);
    Vector start = level->get_start();
    Player player(100, 0, start);

    PlayerManager pm(player, *level);

    while (true) {
        render_controller.render(level, player);
        Command command = input_controller.get_command(dict);
        LevelResult result = command_controller.process_command(pm, command);
        if (result != LevelResult::null) {
            return result;
        }
        result = condition_controller.check_conditions(level, player);
        if (result != LevelResult::null) {
            return result;
        }
    }
}

LevelScreen::LevelScreen(const std::map<char, Command> &dict, InputController& inputController)
        : dict(dict), input_controller(inputController) {};
