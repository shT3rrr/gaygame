
#ifndef GAME_IRENDERCONTROLLER_H
#define GAME_IRENDERCONTROLLER_H


#include "src/logic/level/field/Field.h"

class IRenderController {
public:
    virtual void render(Field *field, const Player &player) = 0;
    virtual bool renderGameOver(Field *field, const Player &player) = 0;
    virtual void setup() {};
    virtual void close() {};
    virtual ~IRenderController() = default;
};


#endif //GAME_IRENDERCONTROLLER_H
