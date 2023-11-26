#include "FtxuiRenderController.h"

#include <memory>

#include "ftxui/component/component.hpp"  // for Renderer, CatchEvent, Horizontal, Menu, Tab
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/event.hpp"               // for Event
#include "ftxui/component/mouse.hpp"               // for Mouse
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/canvas.hpp"                    // for Canvas
#include "ftxui/screen/color.hpp"

#include "ftxui/component/loop.hpp"
#include "ftxui/dom/elements.hpp"
#include "src/logic/level/event/IncreaseHealth.h"
#include "src/logic/level/event/IncreaseScore.h"
#include "src/logic/level/event/ReduceHealth.h"
#include "src/logic/level/event/TeleportPlayer.h"


void FtxuiRenderController::render(Field *field, const Player &player) {
    if (_loop == nullptr) {
        _loop = std::make_unique<ftxui::Loop>(&_screen, _root);
    }

    _screen.PostEvent(ftxui::Event::Custom);
    _model = std::make_unique<FtxuiRenderModel>(field, player);
    _loop->RunOnce();
}

FtxuiRenderController::FtxuiRenderController(ftxui::ScreenInteractive &screen) :
        _screen(screen),
        _root(ftxui::Renderer([this]() {
            return renderInternal();
        })) {
}

ftxui::Component &FtxuiRenderController::root() {
    return _root;
}

ftxui::Element FtxuiRenderController::renderInternal() {
    return ftxui::vbox({
                               ftxui::hbox({
                                                   ftxui::text("Health: "),
                                                   ftxui::text(std::to_string(_model->player.get_health())) |
                                                   ftxui::color(ftxui::Color::Green) | ftxui::bold,
                                                   ftxui::emptyElement() | ftxui::flex_grow,
                                                   ftxui::text("Score: "),
                                                   ftxui::text(std::to_string(_model->player.get_score())) |
                                                   ftxui::color(ftxui::Color::Green) | ftxui::bold,
                                           }),
                               ftxui::separator(),
                               ftxui::hbox({
                                                   ftxui::emptyElement() | ftxui::flex_grow,
                                                   _levelNode,
                                                   ftxui::emptyElement() | ftxui::flex_grow,
                                           }) | ftxui::flex_grow
                       });
}
