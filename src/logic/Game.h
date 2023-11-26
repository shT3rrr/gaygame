#ifndef LB3_GAME_H
#define LB3_GAME_H

#include <map>
#include "src/logic/level/CommandEnum.h"
#include "src/logic/level/controller/common/IControllerFactory.h"

class Game {
public:
    void start(const std::map<char, Command>& dict, IControllerFactory& controllerFactory);
};


#endif //LB3_GAME_H
