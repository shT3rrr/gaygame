#ifndef LB3_CREATELEVEL_H
#define LB3_CREATELEVEL_H


#include "src/logic/level/field/Field.h"

class CreateLevel{
private:
    CreateLevel();

    Field *create_first_level();
    Field *create_zero_level();

public:

    Field* create_level(int number);

    bool is_valid_number(int number);

    static CreateLevel instance() {
        static CreateLevel instance;
        return instance;
    }
};

#endif //LB3_CREATELEVEL_H
