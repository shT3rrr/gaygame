#ifndef LB3_FIELD_H
#define LB3_FIELD_H

#include "Cell.h"
#include "src/util/Vector.h"

class Field {
private:
    int height;
    int width;

    Vector start;
    Vector finish;

    Cell **cells = nullptr;

public:
    ~Field();
    Field(int height, int width);
    Field();
    Field(const Field &otherField);
    Field &operator= (const Field &other);
    void memdel();
    Field &operator= (Field &&other);
    Field(Field &&other);
    Cell &get_cell_for_index(Vector index);
    Vector get_start();
    Vector get_finish();
    void set_start(Vector new_start);
    void set_finish(Vector new_finish);
    int get_heigth();
    int get_width();
};


#endif //LB3_FIELD_H
