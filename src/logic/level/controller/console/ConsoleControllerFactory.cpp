
#include "ConsoleControllerFactory.h"

std::shared_ptr<CommandController> ConsoleControllerFactory::commandController() {
    return std::make_shared<CommandController>();
}

std::shared_ptr<ConditionController> ConsoleControllerFactory::conditionController() {
    return std::make_shared<ConditionController>();
}

std::shared_ptr<IInputController> ConsoleControllerFactory::inputController() {
    return std::make_shared<ConsoleInputController>(std::cin);
}

std::shared_ptr<IRenderController> ConsoleControllerFactory::renderController() {
    return std::make_shared<ConsoleRenderController>();
}
