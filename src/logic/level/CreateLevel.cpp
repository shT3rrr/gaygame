#include <iostream>
#include "CreateLevel.h"
#include "src/logic/level/event/IncreaseHealth.h"
#include "src/logic/level/event/ReduceHealth.h"
#include "src/logic/level/event/IncreaseScore.h"
#include "src/logic/level/event/TeleportPlayer.h"


Field *CreateLevel::create_first_level(){
    Field* actual_field = new Field( 29, 29);

    Vector start;
    start.x = 1;
    start.y = 1;

    Vector finish;
    finish.x = 27;
    finish.y = 27;

    actual_field->set_start(start);
    actual_field->set_finish(finish);

    for (int i = 0; i < actual_field->get_heigth(); ++i) {
        for (int j = 0; j < actual_field->get_width(); ++j) {
            Vector actual_position(i, j);
            Cell& actual_cell = actual_field->get_cell_for_index(actual_position);
            if (i == 0 || j == 0){
                actual_cell.set_is_passable(false);
            }
            if (i == actual_field->get_heigth()-1 || j == actual_field->get_width()-1){
                actual_cell.set_is_passable(false);
            }
            if (i == 1){
                if (j == 6 || j == 10 || j == 12 || j == 16){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 2){
                if (j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j == 18 || j == 19 || j == 21 || j == 22){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 3){
                if (j == 1 || j == 2 || j == 3 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j == 18 || j == 21 || j == 24 || j == 25){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 4){
                if (j == 8 || j == 14 || j == 16 || j == 18 || j == 19 || j == 20 || j == 21 || j == 22 || j == 25 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 5){
                if (j == 3 || j == 4 || j == 5 || j == 6 || j == 7 || j == 8 || j == 10 || j == 11 || j == 13 || j == 14 || j == 16 || j == 17 || j == 18 || j == 21 || j == 26 || j == 27){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 6){
                if (j == 3 || j == 7 || j == 11 || j == 14 || j == 21 || j == 22 || j == 25 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 7){
                if (j == 5 || j == 7 || j == 9 || j == 10 || j == 11 || j == 12 || j == 13 || j == 14 || j == 16 || j == 17 || j == 18 || j == 19 || j == 24 || j == 25){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 8){
                if (j == 1 || j == 2 || j == 3 || j == 5 || j == 7 || j == 11 || j == 16 || j == 19 || j == 20 || j == 23 || j == 24){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 9){
                if (j == 5 || j == 7 || j == 8 || j == 9 || j == 10 || j == 11 || j == 12 || j == 13 || j == 14 || j == 16 || j == 17 || j == 22 || j == 23 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 10){
                if (j == 5 || j == 11 || j == 13 || j == 17 || j == 21 || j == 22 || j == 25 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 11){
                if (j == 1 || j == 2 || j == 3 || j == 4 || j == 5 || j == 7 || j == 8 || j == 9 || j == 10 || j == 11 || j == 13 || j == 16 || j == 17 || j == 20 || j == 21 || j == 24 || j == 25){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 12){
                if (j == 3 || j == 10 || j == 13 || j == 14 || j == 17 || j == 19 || j == 20 || j == 24){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 13){
                if (j == 2 || j == 3 || j == 5 || j == 6 || j == 7 || j == 8 || j == 9 || j == 10 || j == 14 || j == 17 || j == 18 || j == 19 || j == 23 || j == 24 || j == 25 || j == 26 || j == 27){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 14){
                if (j == 6 || j == 13 || j == 14 || j == 19 || j == 22 || j == 23){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 15){
                if (j == 1 || j == 2 || j == 3 || j == 4 || j == 6 || j == 7 || j == 8 || j == 9 || j == 11 || j == 14 || j == 15 || j == 16 || j == 18 || j == 19 || j == 20 || j == 23 || j == 24 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 16){
                if (j == 9 || j == 11 || j == 13 || j == 14 || j == 18 || j == 20 || j == 21 || j == 24 || j == 25 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 17){
                if (j == 3 || j == 6 || j == 7 || j == 8 || j == 9 || j == 11 || j == 12 || j == 13 || j == 21 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 18){
                if (j == 1 || j == 3 || j == 4 || j == 7 || j == 12 || j == 16 || j == 18 || j == 19 || j == 21 || j == 22 || j == 23 || j == 25 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 19){
                if (j == 4 || j == 7 || j == 9 || j == 10 || j == 11 || j == 12 || j == 13 || j == 14 || j == 15 || j == 16 || j == 19 || j == 21 || j == 25){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 20){
                if (j == 1 || j == 3 || j == 4 || j == 6 || j == 7 || j == 11 || j == 16 || j == 18 || j == 19 || j == 20 || j == 21 || j == 22 || j == 24 || j == 25 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 21){
                if (j == 9 || j == 13 || j == 14 || j == 20 || j == 22 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 22){
                if (j == 2 || j == 3 || j == 4 || j == 8 || j == 9 || j == 14 || j == 15 || j == 17 || j == 18 || j == 20 || j == 22 || j == 24 || j == 26){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 23){
                if (j == 2 || j == 6 || j == 8 || j == 11 || j == 12 || j == 13 || j == 14 || j == 17 || j == 20 || j == 24){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 24){
                if (j == 2 || j == 3 || j == 6 || j == 7 || j == 8 || j == 12 || j == 16 || j == 17 || j == 18 || j == 19 || j == 20 || j == 21 || j == 22 || j == 23 || j == 24 || j == 25 || j == 27){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 25){
                if (j == 3 || j == 4 || j == 8 || j == 9 || j == 10 || j == 12 || j == 13 || j == 14 || j == 16 || j == 20){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 26){
                if (j == 1 || j == 2 || j == 3 || j == 6 || j == 8 || j == 10 || j == 14 || j == 18 || j == 20 || j == 21 || j == 22 || j == 24 || j == 25 || j == 26 || j == 27){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 27){
                if (j == 6 || j == 10 || j == 12 || j == 14 || j == 18){
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 3 && j == 19){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 6 && j == 13){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 8 && j == 17){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 12 && j == 9){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 19 && j == 26){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 22 && j == 13){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 23 && j == 16){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 2 && j == 20){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 2 && j == 26){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 6 && j == 2){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 7 && j == 6){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 9 && j == 25){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 10 && j == 23){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 13 && j == 16){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 13 && j == 21){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 14 && j == 12){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 19 && j == 2){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 19 && j == 22){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 21 && j == 8){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 25 && j == 22){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 27 && j == 8){
                ReduceHealth* gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 1 && j == 11){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 3 && j == 26){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 4 && j == 17){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 6 && j == 27){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 8 && j == 12){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 12 && j == 2){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 14 && j == 24){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 18 && j == 13){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 19 && j == 20){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 21 && j == 21){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 25 && j == 2){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 25 && j == 27){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 27 && j == 13){
                IncreaseScore* gameEvent = new IncreaseScore;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 22 && j == 16){
                TeleportPlayer* gameEvent = new TeleportPlayer;
                Vector new_position;
                new_position.x = 12;
                new_position.y = 25;

                gameEvent->set_new_position(new_position);
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 24 && j == 26){
                TeleportPlayer* gameEvent = new TeleportPlayer;
                Vector new_position;
                new_position.x = 27;
                new_position.y = 1;

                gameEvent->set_new_position(new_position);
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 10 && j == 12){
                TeleportPlayer* gameEvent = new TeleportPlayer;
                Vector new_position;
                new_position.x = 24;
                new_position.y = 13;

                gameEvent->set_new_position(new_position);
                actual_cell.set_gameEvent(gameEvent);
            }
        }
    }
    return actual_field;
}

Field *CreateLevel::create_zero_level() {
    Field* actual_field = new Field( 5, 5);

    Vector start;
    start.x = 1;
    start.y = 1;

    Vector finish;
    finish.x = 3;
    finish.y = 3;

    actual_field->set_start(start);
    actual_field->set_finish(finish);

    for (int i = 0; i < actual_field->get_heigth(); ++i) {
        for (int j = 0; j < actual_field->get_width(); ++j) {
            Vector actual_position(i, j);
            Cell &actual_cell = actual_field->get_cell_for_index(actual_position);
            if (i == 0 || j == 0) {
                actual_cell.set_is_passable(false);
            }
            if (i == actual_field->get_heigth() - 1 || j == actual_field->get_width() - 1) {
                actual_cell.set_is_passable(false);
            }
            if (i == 2) {
                if (j == 1 || j == 2 || j == 3) {
                    actual_cell.set_is_passable(false);
                }
            }
            if (i == 1 && j == 2) {
                ReduceHealth *gameEvent = new ReduceHealth;
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 1 && j == 3){
                TeleportPlayer* gameEvent = new TeleportPlayer;
                Vector new_position;
                new_position.x = 3;
                new_position.y = 1;

                gameEvent->set_new_position(new_position);
                actual_cell.set_gameEvent(gameEvent);
            }
            if (i == 3 && j == 2){
                IncreaseHealth* gameEvent = new IncreaseHealth;
                actual_cell.set_gameEvent(gameEvent);
            }

        }
    }
    return actual_field;
}


CreateLevel::CreateLevel() {
}

Field *CreateLevel::create_level(int number) {
    switch (number) {
        case 0:
            return create_zero_level();
        case 1:
            return create_first_level();
    }
    return nullptr;
}

bool CreateLevel::is_valid_number(int number) {
    return number == 0 || number == 1;
}
