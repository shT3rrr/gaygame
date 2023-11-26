
#ifndef GAME_FTXUIRENDERMODEL_H
#define GAME_FTXUIRENDERMODEL_H


#include "src/logic/level/field/Field.h"

struct FtxuiRenderModel {
    FtxuiRenderModel(Field *field, const Player &player);

    Field *field;
    const Player &player;
};


#endif //GAME_FTXUIRENDERMODEL_H
