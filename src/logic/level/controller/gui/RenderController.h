//
// Created by Илья on 06.11.2023.
//

#ifndef GAME_RENDERCONTROLLER_H
#define GAME_RENDERCONTROLLER_H


#include "src/logic/level/field/Field.h"

class RenderController {
private:
    void print_level(Field* act_field, Vector player_position);
public:
    void render(Field *field, const Player &player);
};


#endif //GAME_RENDERCONTROLLER_H
