#include "src/logic/Game.h"
#include "src/config/FileReader.h"

int main(){
    FileReader r("/mnt/c/lb3/control");
    std::map<char, Command> dict = r.read_from_file();

    Game g;
    g.start(dict);
}

