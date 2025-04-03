#include "../include/NumberSystemConverter.h"

char NumberSystemConverter::intToChar(int num) {
    if (num >= 0 && num <= 9) {
        return static_cast<char>(num + '0');
    } else if (num >= 10 && num <= 35) {
        return static_cast<char>(num - 10 + 'A');
    }
    throw std::invalid_argument("Недопустимое число для преобразования в символ");
}

int NumberSystemConverter::charToInt(char c) {
    c = toupper(c);
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    throw std::invalid_argument("Недопустимый символ для преобразования в int");
}

std::string NumberSystemConverter::decimalToBase(long long decimal, int base) {
    if (decimal == 0) {
        return "0";
    }
    
    bool isNegative = false;
    if (decimal < 0) {
        isNegative = true;
        decimal = -decimal;
    }

    std::string result;
    while (decimal > 0) {
        int remainder = decimal % base;
        result.push_back(intToChar(remainder));
        decimal /= base;
    }
    
    if (isNegative) {
        result.push_back('-');
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

long long NumberSystemConverter::baseToDecimal(const std::string& number, int base) {
    if (number.empty()) {
        return 0;
    }

    long long decimal = 0;
    size_t startIndex = 0;
    bool isNegative = false;

    if (number[0] == '-') {
        isNegative = true;
        startIndex = 1;
    }

    for (size_t i = startIndex; i < number.size(); ++i) {
        decimal = decimal * base + charToInt(number[i]);
    }

    return isNegative ? -decimal : decimal;
}

std::string NumberSystemConverter::convertBase(const std::string& number, int fromBase, int toBase) {
    if (fromBase == toBase) {
        return number;
    }
    long long decimal = baseToDecimal(number, fromBase);
    return decimalToBase(decimal, toBase);
}

bool NumberSystemConverter::isValidNumber(const std::string& number, int base) {
    if (base < 2 || base > 36) {
        return false;
    }

    if (number.empty()) {
        return false;
    }

    size_t startIndex = 0;
    if (number[0] == '-') {
        startIndex = 1;
        if (number.size() == 1) {
            return false; // Только минус без цифр
        }
    }

    for (size_t i = startIndex; i < number.size(); ++i) {
        char c = number[i];
        int value;
        try {
            value = charToInt(c);
        } catch (const std::invalid_argument&) {
            return false;
        }
        if (value >= base) {
            return false;
        }
    }

    return true;
}

std::string NumberSystemConverter::addNumbers(const std::string& num1, int base1, 
                                            const std::string& num2, int base2, 
                                            int resultBase) {
    if (!isValidNumber(num1, base1)) {
        throw std::invalid_argument("Первое число недопустимо для своей системы счисления");
    }
    if (!isValidNumber(num2, base2)) {
        throw std::invalid_argument("Второе число недопустимо для своей системы счисления");
    }
    if (resultBase < 2 || resultBase > 36) {
        throw std::invalid_argument("Система счисления должна быть от 2 до 36.");
    }

    long long decimal1 = baseToDecimal(num1, base1);
    long long decimal2 = baseToDecimal(num2, base2);
    long long sum = decimal1 + decimal2;
    
    return decimalToBase(sum, resultBase);
}