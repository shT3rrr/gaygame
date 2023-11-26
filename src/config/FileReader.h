#ifndef LB3_READERFROMFILE_H
#define LB3_READERFROMFILE_H


#include <string>
#include <map>
#include <vector>
#include "src/logic/level/CommandEnum.h"

class FileReader {
private:
    std::string path;
    std::vector<std::string> split(const std::string& str, const std::string& delim);
    Command str_to_enum(const std::string& str_direction);
    std::string enum_to_str(Command command);
public:
    FileReader(std::string path);
    std::map<char, Command> read_from_file();
};


#endif //LB3_READERFROMFILE_H
