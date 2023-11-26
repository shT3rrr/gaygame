#include <iostream>
#include "Game.h"
#include "src/logic/level/LevelScreen.h"
#include "src/logic/menu/MenuScreen.h"


void Game::start(const std::map<char, Command>& dict, IControllerFactory& controllerFactory) {
    while (true) {
        int level_number = MenuScreen().run();
        auto& inputStream = std::cin;

        LevelResult result = LevelScreen(dict, controllerFactory).run(level_number);
        if (result == LevelResult::EXIT){
            return;
        }
        else if (result == LevelResult::CHOOSE_NEW_LEVEL){
            continue;
        }
    }
}