
#ifndef GAME_CONSOLECONTROLLERFACTORY_H
#define GAME_CONSOLECONTROLLERFACTORY_H


#include <iostream>
#include "src/logic/level/controller/common/IControllerFactory.h"
#include "ConsoleInputController.h"
#include "ConsoleRenderController.h"

class ConsoleControllerFactory : public IControllerFactory {
public:
     std::shared_ptr<CommandController> commandController() override;;
     std::shared_ptr<ConditionController> conditionController() override;;
     std::shared_ptr<IInputController> inputController() override;;
     std::shared_ptr<IRenderController> renderController() override;;
};


#endif //GAME_CONSOLECONTROLLERFACTORY_H
