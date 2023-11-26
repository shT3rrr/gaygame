#include "src/logic/Game.h"
#include "src/config/FileReader.h"
#include "src/logic/level/controller/console/ConsoleControllerFactory.h"
#include "src/logic/level/controller/ftxui/FtxuiControllerFactory.h"

int main(){
    FileReader r("/Users/m.besogonov/CLionProjects/gaygame/control");
    std::map<char, Command> dict = r.read_from_file();

    FtxuiControllerFactory controllerFactory;

    Game g;
    g.start(dict, controllerFactory);
}

