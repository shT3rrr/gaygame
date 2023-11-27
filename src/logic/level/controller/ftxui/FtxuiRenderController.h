
#ifndef GAME_FTXUIRENDERCONTROLLER_H
#define GAME_FTXUIRENDERCONTROLLER_H


#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/loop.hpp>
#include <ftxui/dom/node.hpp>
#include "src/logic/level/controller/common/IRenderController.h"
#include "FtxuiRenderModel.h"
#include "FtxuiLevelNode.h"

class FtxuiRenderController : public IRenderController {
private:
    ftxui::ScreenInteractive& _screen;
    ftxui::Component _root;
    std::unique_ptr<ftxui::Loop> _loop;
    std::unique_ptr<FtxuiRenderModel> _model;
    std::shared_ptr<FtxuiLevelNode> _levelNode = std::make_shared<FtxuiLevelNode>(_model);

    bool _returnToMenuRequested = false;
    std::chrono::milliseconds _returnToMenu;

    ftxui::Element renderInternal();
    void draw();
public:
    explicit FtxuiRenderController(ftxui::ScreenInteractive &screen);

    void render(Field *field, const Player &player) override;
    bool renderGameOver(Field *field, const Player &player) override;
    void setup() override;
    void close() override;

    ftxui::Component & root();
};


#endif //GAME_FTXUIRENDERCONTROLLER_H
