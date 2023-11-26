
#ifndef GAME_I_INPUT_CONTROLLER_H
#define GAME_I_INPUT_CONTROLLER_H

#include <map>
#include "src/logic/level/CommandEnum.h"

class IInputController {
public:
    virtual Command get_command(const std::map<char, Command> &dict) = 0;
    virtual ~IInputController() = default;
};


#endif //GAME_I_INPUT_CONTROLLER_H
