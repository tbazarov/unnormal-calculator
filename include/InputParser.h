#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>
#include <vector>

struct InputData {
    int baseA;
    std::string numberA;
    int baseB;
    std::string numberB;
    int baseC;
};

class InputParser {
public:
    static InputData parseInput(const std::vector<std::string>& lines);
    static std::vector<std::string> readLines(const std::string& filename);
private:
    static bool parseLine(const std::string& line, int& base, std::string& number);
};

#endif // INPUT_PARSER_H