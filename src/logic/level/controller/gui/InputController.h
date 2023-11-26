//
// Created by Илья on 06.11.2023.
//

#ifndef GAME_INPUTCONTROLLER_H
#define GAME_INPUTCONTROLLER_H


#include <map>
#include "src/logic/level/CommandEnum.h"

class InputController {
private:
    std::basic_istream<char> &stream;
public:
    InputController(std::basic_istream<char> &stream);

    Command get_command(const std::map<char, Command> &dict);
};


#endif //GAME_INPUTCONTROLLER_H
