//
// Created by Илья on 06.11.2023.
//

#ifndef GAME_COMMANDCONTROLLER_H
#define GAME_COMMANDCONTROLLER_H


#include "src/logic/level/entity/PlayerManager.h"
#include "src/logic/level/CommandEnum.h"
#include "src/logic/level/LevelResultEnum.h"

class CommandController {
public:
    LevelResult process_command(PlayerManager &pm, Command command);
};


#endif //GAME_COMMANDCONTROLLER_H
