//
// Created by Илья on 05.11.2023.
//

#ifndef GAME_LEVELSCREEN_H
#define GAME_LEVELSCREEN_H


#include <map>
#include "CommandEnum.h"
#include "LevelResultEnum.h"
#include "src/logic/level/controller/common/IInputController.h"
#include "src/logic/level/controller/common/IRenderController.h"
#include "src/logic/level/controller/common/CommandController.h"
#include "src/logic/level/controller/common/ConditionController.h"
#include "src/logic/level/controller/common/IControllerFactory.h"

class LevelScreen {
public:
    LevelResult run(int level_number);
    LevelScreen(const std::map<char, Command> &dict, IControllerFactory& controllerFactory);
private:
    const std::map<char, Command>& dict;

    std::shared_ptr<IInputController> input_controller;
    std::shared_ptr<CommandController> command_controller;
    std::shared_ptr<IRenderController> render_controller;
    std::shared_ptr<ConditionController> condition_controller;
};


#endif //GAME_LEVELSCREEN_H
