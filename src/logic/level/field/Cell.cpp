#include "Cell.h"

Cell::Cell(bool new_passability):
        is_passable(new_passability){
}

Cell::Cell(){
        is_passable = true;
}

bool Cell::get_is_passable() {
    return is_passable;
}

void Cell::set_is_passable(bool new_passability) {
    is_passable = new_passability;
}

void Cell::set_gameEvent(IGameEvent *gameEvent) {
    this->gameEvent = gameEvent;
}

Cell::~Cell() {
    delete gameEvent;
}

IGameEvent* Cell::get_gameEvent() {
    return this->gameEvent;
}


