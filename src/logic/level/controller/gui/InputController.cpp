//
// Created by Илья on 06.11.2023.
//


#include <iostream>
#include "InputController.h"

Command InputController::get_command(const std::map<char, Command> &dict) {
    std::string input;
    while (true) {
        getline(stream, input);

        if (input.empty() || !dict.contains(input[0])) {
            std::cout << "Incorrect input" << '\n';
            continue;
        }
        Command command = dict.at(input[0]);
        return command;
    }
}

InputController::InputController(std::basic_istream<char> &stream)
        : stream(stream) {}
