#ifndef NUMBER_SYSTEM_CONVERTER_H
#define NUMBER_SYSTEM_CONVERTER_H

#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

class NumberSystemConverter {
public:
    static std::string addNumbers(const std::string& num1, int base1, 
                                const std::string& num2, int base2, 
                                int resultBase);
    static std::string convertBase(const std::string& number, 
                                 int fromBase, int toBase);
    static bool isValidNumber(const std::string& number, int base);

private:
    static char intToChar(int num);
    static int charToInt(char c);
    static std::string decimalToBase(long long decimal, int base);
    static long long baseToDecimal(const std::string& number, int base);
};

#endif // NUMBER_SYSTEM_CONVERTER_H