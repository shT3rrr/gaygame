//
// Created by Илья on 06.11.2023.
//
#include <iostream>
#include <string>
#include "ConsoleRenderController.h"
#include "src/logic/level/event/IncreaseHealth.h"
#include "src/logic/level/event/IncreaseScore.h"
#include "src/logic/level/event/ReduceHealth.h"
#include "src/logic/level/event/TeleportPlayer.h"

void ConsoleRenderController::print_level(Field* act_field, Vector player_position) {
    for (int i = 0; i < act_field->get_heigth(); ++i) {
        for (int j = 0; j < act_field->get_width(); ++j) {
            Vector act_pos(i, j);
            Cell &actual_cell = act_field->get_cell_for_index(act_pos);
            if (actual_cell.get_is_passable()) {
                if (i == player_position.x && j == player_position.y) {
                    printf("\x1B[31mP\033[0m");
                } else if (i == act_field->get_finish().x && j == act_field->get_finish().y) {
                    std::cout << "F";
                } else {
                    IGameEvent* event = actual_cell.get_gameEvent();
                    if (event == nullptr) {
                        std::cout << " ";
                    } else {
                        if (dynamic_cast<IncreaseHealth*>(event)) {
                            std::cout << "+";
                        }
                        else if (dynamic_cast<IncreaseScore*>(event)) {
                            std::cout << "*";
                        }
                        else if (dynamic_cast<ReduceHealth*>(event)) {
                            std::cout << "%";
                        }
                        else if (dynamic_cast<TeleportPlayer*>(event)) {
                            std::cout << "@";
                        }

                    };
                }
            } else {
                std::cout << "║";
            }
            std::cout<< " ";
        }
        std::cout << '\n';
    }
}

void ConsoleRenderController::render(Field *field, const Player &player) {
    ConsoleRenderController::print_level(field, player.get_position());
    std::cout << "Health: " << player.get_health() << "  Score: " << player.get_score() << std::endl;
}

