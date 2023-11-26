
#ifndef GAME_ICONTROLLERFACTORY_H
#define GAME_ICONTROLLERFACTORY_H


#include <memory>
#include "CommandController.h"
#include "ConditionController.h"
#include "IInputController.h"
#include "IRenderController.h"

class IControllerFactory {
public:
    virtual std::shared_ptr<CommandController> commandController() = 0;
    virtual std::shared_ptr<ConditionController> conditionController() = 0;
    virtual std::shared_ptr<IInputController> inputController() = 0;
    virtual std::shared_ptr<IRenderController> renderController() = 0;
};


#endif //GAME_ICONTROLLERFACTORY_H
