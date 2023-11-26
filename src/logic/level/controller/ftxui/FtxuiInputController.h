
#ifndef GAME_FTXUIINPUTCONTROLLER_H
#define GAME_FTXUIINPUTCONTROLLER_H

#include "ftxui/screen/screen.hpp"
#include "ftxui/component/component.hpp"


#include "src/logic/level/controller/common/IInputController.h"

class FtxuiInputController : public IInputController {
private:
    ftxui::ScreenInteractive& _screen;
    ftxui::Component& _component;
    char _lastCommand = 0;
public:
    explicit FtxuiInputController(ftxui::ScreenInteractive &screen, ftxui::Component& component) : _screen(screen), _component(component) {
        component |= ftxui::CatchEvent([this](const ftxui::Event& event) {
            if (event.is_character()) {
                _lastCommand = event.character()[0];
            }
            return true;
        });
    }

    Command get_command(const std::map<char, Command> &dict) override {
        if (dict.contains(_lastCommand)) {
            auto result = dict.at(_lastCommand);
            _lastCommand = 0;
            return result;
        }
        return Command::null;
    }
};


#endif //GAME_FTXUIINPUTCONTROLLER_H
