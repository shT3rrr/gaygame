#ifndef LB3_CELL_H
#define LB3_CELL_H


#include "src/util/Vector.h"
#include "src/logic/level/event/IGameEvent.h"

class Cell {
private:
    bool is_passable;
    IGameEvent* gameEvent = nullptr;

public:
    IGameEvent* get_gameEvent();
    void set_gameEvent(IGameEvent* gameEvent);

    Cell(bool is_passable);
    Cell();

    bool get_is_passable();
    void set_is_passable(bool new_passability);
    ~Cell();
};


#endif //LB3_CELL_H
