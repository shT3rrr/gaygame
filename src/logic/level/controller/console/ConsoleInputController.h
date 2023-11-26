//
// Created by Илья on 06.11.2023.
//

#ifndef GAME_CONSOLEINPUTCONTROLLER_H
#define GAME_CONSOLEINPUTCONTROLLER_H


#include <map>
#include "src/logic/level/CommandEnum.h"
#include "src/logic/level/controller/common/IInputController.h"

class ConsoleInputController : public IInputController {
private:
    std::basic_istream<char> &stream;
public:
    ConsoleInputController(std::basic_istream<char> &stream);

    Command get_command(const std::map<char, Command> &dict) override;

};


#endif //GAME_CONSOLEINPUTCONTROLLER_H
