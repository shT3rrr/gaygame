#include "Field.h"
#include <stdexcept>
#include <algorithm>

Field::Field(int new_height, int new_width) {
    if (new_height < 2 || new_width < 2) {
        throw new std::invalid_argument("passed parameters must be more than 2");
    }
    height = new_height;
    width = new_width;
    start = Vector(1,1);
    finish = Vector(width-1, height-1);
    cells = new Cell *[width];
    for (int i = 0; i < width; ++i) {
        cells[i] = new Cell[height];
    }
}

Field::Field() {
    height = 3;
    width = 3;
    start = Vector(1,1);
    finish = Vector(width-1, height-1);
}

Field::~Field() {
    memdel();
}

Field::Field(const Field &otherField) {
    *this = otherField;
}

Field &Field::operator=(const Field &otherField) {
    if (this == &otherField) {
        return *this;
    }

    this->width = otherField.width;
    this->height = otherField.height;
    this->start = otherField.start;
    this->finish = otherField.finish;

    memdel();

    cells = new Cell *[width];
    for (int i = 0; i < width; ++i) {
        cells[i] = new Cell[height];
        for (int j = 0; j < height; ++j) {
            cells[i][j] = otherField.cells[i][j];
        }
    }

    return *this;
}

void Field::memdel() {
    if (cells != nullptr) {
        for (int i = 0; i < width; ++i) {
            delete[] cells[i];
        }
        delete[] cells;
        cells = nullptr;
    }
}

Field &Field::operator=(Field &&otherField) {
    if (this == &otherField) {
        return *this;
    }

    this->width = otherField.width;
    this->height = otherField.height;
    this->start = otherField.start;
    this->finish = otherField.finish;

    memdel();

    this->cells = otherField.cells;
    otherField.cells = nullptr;

    return *this;
}

Field::Field(Field &&otherField) {
    *this = std::move(otherField);
}

Cell & Field::get_cell_for_index(Vector index) {
    return this->cells[index.x][index.y];
}

int Field::get_heigth() {
    return this->height;
}

int Field::get_width() {
    return this->width;
}

void Field::set_start(Vector new_start) {
    this->start = new_start;
}

void Field::set_finish(Vector new_finish) {
    this->finish = new_finish;
}

Vector Field::get_start() {
    return this->start;
}

Vector Field::get_finish() {
    return this->finish;
}



