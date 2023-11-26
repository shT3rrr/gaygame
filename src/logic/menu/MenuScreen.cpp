//
// Created by Илья on 06.11.2023.
//

#include <iostream>
#include "MenuScreen.h"
#include "src/logic/level/CreateLevel.h"

int MenuScreen::run() {
    int level_number = -1;
    std::string input;

    while(true) {
        std::cout << "Choose the level (0/1)" << '\n';

        getline(std::cin, input);

        if (sscanf(input.c_str(), "%d", &level_number) != 1) {
            std::cout << "Incorrect level number" << '\n';
            continue;
        }

        if (!CreateLevel::instance().is_valid_number(level_number)) {
            std::cout << "Incorrect level number" << '\n';
            continue;
        }

        return level_number;
    }
}

MenuScreen::MenuScreen() {

}
