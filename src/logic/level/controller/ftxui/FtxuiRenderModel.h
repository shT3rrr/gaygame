
#ifndef GAME_FTXUIRENDERMODEL_H
#define GAME_FTXUIRENDERMODEL_H


#include "src/logic/level/field/Field.h"

struct FtxuiRenderModel {
    FtxuiRenderModel(bool isGameOver, Field *field, const Player &player);

    bool isGameOver;
    Field *field;
    const Player &player;
};


#endif //GAME_FTXUIRENDERMODEL_H
