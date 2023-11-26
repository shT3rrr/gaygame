#include "FileReader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>
#include <set>

std::map<char, Command> FileReader::read_from_file() {
    std::ifstream stream(path);

    if (!stream) {
        throw std::logic_error("Failed to open file: " + std::string(path));
    }

    std::stringstream buffer;
    buffer << stream.rdbuf();
    std::string result = buffer.str();
    std::string delim = "\n";

    std::vector<std::string> arr = split(result, delim);

    std::map<char, Command> dict;

    std::set<Command> all_directions = {
            Command::DOWN,
            Command::UP,
            Command::RIGHT,
            Command::LEFT,
            Command::BACK,
            Command::QUIT
    };

    std::set<char> busy_buttons = {};

    delim = "=";

    if (arr.size()>6){
        throw std::logic_error("too many lines in the control file");
    }

    for (const auto & i : arr) {
        std::vector<std::string> splitted = split(i, delim);
        if (splitted.size() != 2){
            throw std::logic_error("invalid control file");
        }
        auto direction = splitted[1];
        auto key = splitted[0];

        if (key.size() != 1){
            throw std::logic_error("invalid button: " + key);
        }

        if (!busy_buttons.contains(key[0])){
            busy_buttons.insert(key[0]);
        }

        Command command = str_to_enum(direction);
        if (command == Command::null){
            throw std::logic_error("invalid command: " + direction);
        }

        if (all_directions.contains(command)){
            dict[key[0]] = command;
            all_directions.extract(command);
        }
    }

    if (!all_directions.empty() || busy_buttons.size() != 6){
        if (!all_directions.empty()){
            std::string free_commands;

            std::set<Command>::iterator i;
            for (i = all_directions.begin(); i != all_directions.end(); ++i) {
                Command ptr = *i;
                free_commands += enum_to_str(ptr);
                free_commands += " ";
            }
            throw std::logic_error("there are no corresponding buttons for the following commands: " + free_commands);
        }
        throw std::logic_error("the same button/buttons is used for different commands");
    }

    return dict;
}

std::vector<std::string> FileReader::split(const std::string& str, const std::string& delim) {
    std::vector<std::string> word;
    std::string token;
    size_t last = 0;
    size_t next;
    while ((next = str.find(delim, last)) != std::string::npos) {
        word.push_back(std::string(str.substr(last, next - last)));
        last = next + 1;
    }
    word.push_back(std::string(str.substr(last)));
    return word;
}

FileReader::FileReader(std::string path) : path(std::move(path)) {
}

Command FileReader::str_to_enum(const std::string& str_direction) {
    if (str_direction == "up") {
        return Command::UP;
    }
    if (str_direction == "down") {
        return Command::DOWN;
    }
    if (str_direction == "left") {
        return Command::LEFT;
    }
    if (str_direction == "right") {
        return Command::RIGHT;
    }
    if (str_direction == "back") {
        return Command::BACK;
    }
    if (str_direction == "quit") {
        return Command::QUIT;
    }
    return Command::null;
}

std::string FileReader::enum_to_str(Command command) {
    if (command == Command::UP) {
        return "up";
    }
    if (command == Command::DOWN) {
        return "down";
    }
    if (command == Command::LEFT) {
        return "left";
    }
    if (command == Command::RIGHT) {
        return "right";
    }
    if (command == Command::BACK) {
        return "back";
    }
    if (command == Command::QUIT) {
        return "quit";
    }
    return "null";
}

