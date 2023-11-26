
#ifndef GAME_FTXUICONTROLLERFACTORY_H
#define GAME_FTXUICONTROLLERFACTORY_H

#include "src/logic/level/controller/common/IControllerFactory.h"
#include "ftxui/component/screen_interactive.hpp"
#include "FtxuiInputController.h"
#include "FtxuiRenderController.h"


class FtxuiControllerFactory : public IControllerFactory {
private:
    ftxui::ScreenInteractive _screen = ftxui::ScreenInteractive::Fullscreen();
    std::shared_ptr<FtxuiInputController> _inputController;
    std::shared_ptr<FtxuiRenderController> _renderController;

public:
    FtxuiControllerFactory() {
        _renderController = std::make_shared<FtxuiRenderController>(_screen);
        _inputController = std::make_shared<FtxuiInputController>(_screen, _renderController->root());
    }

    std::shared_ptr<CommandController> commandController() override {
        return std::make_shared<CommandController>();
    }

    std::shared_ptr<ConditionController> conditionController() override {
        return std::make_shared<ConditionController>();
    }

    std::shared_ptr<IInputController> inputController() override {
        return _inputController;
    }

    std::shared_ptr<IRenderController> renderController() override {
        return _renderController;
    }
};


#endif //GAME_FTXUICONTROLLERFACTORY_H
