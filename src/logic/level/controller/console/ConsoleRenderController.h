//
// Created by Илья on 06.11.2023.
//

#ifndef GAME_CONSOLERENDERCONTROLLER_H
#define GAME_CONSOLERENDERCONTROLLER_H


#include "src/logic/level/field/Field.h"
#include "src/logic/level/controller/common/IRenderController.h"

class ConsoleRenderController : public IRenderController {
private:
    void print_level(Field* act_field, Vector player_position);
public:
    void render(Field *field, const Player &player) override;
    bool renderGameOver(Field *field, const Player &player) override;
};


#endif //GAME_CONSOLERENDERCONTROLLER_H
