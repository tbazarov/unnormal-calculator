#include <iostream>
#include <vector>
#include "../include/NumberSystemConverter.h"
#include "../include/InputParser.h"
#include "../include/FileHandler.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    try {
        // считывание поступающих данных
        auto lines = InputParser::readLines(argv[1]);
        InputData input = InputParser::parseInput(lines);

        // проверяю числа
        if (!NumberSystemConverter::isValidNumber(input.numberA, input.baseA)) {
            throw std::invalid_argument("Данное число А не принадлежит указанной системе счисления");
        }
        if (!NumberSystemConverter::isValidNumber(input.numberB, input.baseB)) {
            throw std::invalid_argument("Данное число В не принадлежит указанной системе счисления");
        }

        
        std::string result = NumberSystemConverter::addNumbers(
            input.numberA, input.baseA,
            input.numberB, input.baseB,
            input.baseC
        );

      
        FileHandler::writeResult(argv[2], result, input.baseC);

        std::cout << "четко, результат в output.txt " << argv[2] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ты лох: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}