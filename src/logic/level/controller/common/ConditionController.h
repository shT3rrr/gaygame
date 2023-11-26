#ifndef GAME_CONDITIONCONTROLLER_H
#define GAME_CONDITIONCONTROLLER_H


#include "src/logic/level/LevelResultEnum.h"
#include "src/logic/level/field/Field.h"

class ConditionController {

public:
    LevelResult check_conditions(Field *field, Player &player);
};


#endif //GAME_CONDITIONCONTROLLER_H
