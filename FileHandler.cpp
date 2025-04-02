#include "FileHandler.h"
#include <fstream>

void FileHandler::writeResult(const std::string& filename, const std::string& result, int base) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Данный файл не открывается " + filename);
    }
    file << base << ": \"" << result << "\"\n";
}