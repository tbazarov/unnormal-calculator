#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>

class FileHandler {
public:
    static void writeResult(const std::string& filename, const std::string& result, int base);
};

#endif // FILE_HANDLER_H