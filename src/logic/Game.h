#ifndef LB3_GAME_H
#define LB3_GAME_H

#include <map>
#include "src/logic/level/CommandEnum.h"

class Game {
public:
    void start(const std::map<char, Command>& dict);
};


#endif //LB3_GAME_H
