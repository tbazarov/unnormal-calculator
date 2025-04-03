#include "../include/InputParser.h"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

bool InputParser::parseLine(const std::string& line, int& base, std::string& number) {
    size_t colonPos = line.find(':');
    if (colonPos == std::string::npos) {
        return false;
    }

    std::string baseStr = line.substr(0, colonPos);
    std::string numberStr = line.substr(colonPos + 1);

    // еврейское обрезание пробелов
    baseStr.erase(std::remove_if(baseStr.begin(), baseStr.end(), ::isspace), baseStr.end());
    numberStr.erase(std::remove_if(numberStr.begin(), numberStr.end(), ::isspace), numberStr.end());

    // игнор кавычек
    if (!numberStr.empty() && numberStr.front() == '"' && numberStr.back() == '"') {
        numberStr = numberStr.substr(1, numberStr.size() - 2);
    }

    try {
        base = std::stoi(baseStr);
    } catch (...) {
        return false;
    }

    if (base < 2 || base > 36) {
        return false;
    }

    number = numberStr;
    return true;
}

InputData InputParser::parseInput(const std::vector<std::string>& lines) {
    InputData data;
    bool foundA = false, foundB = false, foundC = false;

    for (const auto& line : lines) {
        if (line.empty()) continue;

        if (!foundA) {
            if (parseLine(line, data.baseA, data.numberA)) {
                foundA = true;
                continue;
            }
        }

        if (!foundB) {
            if (parseLine(line, data.baseB, data.numberB)) {
                foundB = true;
                continue;
            }
        }

        if (!foundC) {
            try {
                data.baseC = std::stoi(line);
                if (data.baseC >= 2 && data.baseC <= 36) {
                    foundC = true;
                }
            } catch (...) {
                
            }
        }
    }

    if (!foundA || !foundB || !foundC) {
        throw std::invalid_argument("Неверный формат входного файла");
    }

    return data;
}

std::vector<std::string> InputParser::readLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    return lines;
}