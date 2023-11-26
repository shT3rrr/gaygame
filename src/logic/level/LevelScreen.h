//
// Created by Илья on 05.11.2023.
//

#ifndef GAME_LEVELSCREEN_H
#define GAME_LEVELSCREEN_H


#include <map>
#include "CommandEnum.h"
#include "LevelResultEnum.h"
#include "src/logic/level/controller/gui/InputController.h"
#include "src/logic/level/controller/gui/CommandController.h"
#include "src/logic/level/controller/gui/RenderController.h"
#include "src/logic/level/controller/gui/ConditionController.h"

class LevelScreen {
public:
    LevelResult run(int level_number);
    LevelScreen(const std::map<char, Command> &dict, InputController& inputController);
private:
    const std::map<char, Command>& dict;
    InputController& input_controller;
    CommandController command_controller;
    RenderController render_controller;
    ConditionController condition_controller;
};


#endif //GAME_LEVELSCREEN_H
