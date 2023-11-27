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
#include <chrono>


void FtxuiRenderController::draw() {
    if (_loop == nullptr) {
        _loop = std::make_unique<ftxui::Loop>(&_screen, _root);
    }

    _loop->RunOnceBlocking();
    _screen.PostEvent(ftxui::Event::Custom);
}

void FtxuiRenderController::render(Field *field, const Player &player) {
    _model = std::make_unique<FtxuiRenderModel>(false, field, player);
    draw();
}

bool FtxuiRenderController::renderGameOver(Field *field, const Player &player) {
    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    if (!_returnToMenuRequested) {
        _returnToMenuRequested = true;
        _returnToMenu = now + std::chrono::seconds(5);
    }
    if (_returnToMenu < now) {
        return true;
    }

    _model = std::make_unique<FtxuiRenderModel>(true, field, player);
    draw();
    return false;
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
    if (_model->isGameOver) {
        auto caption = "";
        bool positive;
        if (_model->player.get_position().x == _model->field->get_finish().x &&
            _model->player.get_position().y == _model->field->get_finish().y) {
            if (_model->player.get_score() == 1000) {
                caption = "Wow, you are cool!";
            } else {
                caption = "Yay, you won";
            }
            positive = true;
        } else {
            caption = "Haha, you died";
            positive = false;
        }

        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()
        );

        return ftxui::vbox({
                                   ftxui::paragraphAlignCenter("GAME OVER") | ftxui::bold |
                                   ftxui::color(positive ? ftxui::Color::Green : ftxui::Color::Red),
                                   ftxui::paragraphAlignCenter(caption) | ftxui::color(ftxui::Color::GrayLight),
                                   ftxui::text(""),
                                   ftxui::paragraphAlignCenter("Return to menu in " +
                                                               std::to_string(
                                                                       std::chrono::duration_cast<std::chrono::seconds>(
                                                                               (_returnToMenu - now)
                                                                       ).count()) + "..."),
                           }) | ftxui::center;
    } else {
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
}

void FtxuiRenderController::setup() {
    _returnToMenuRequested = false;
    _screen.SetCursor(ftxui::Screen::Cursor{0, 0, ftxui::Screen::Cursor::Hidden});
}

void FtxuiRenderController::close() {
    _screen.Clear();
    _loop = nullptr;
}
