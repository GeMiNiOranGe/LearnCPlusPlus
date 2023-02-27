#include <iostream>
#include <stack>
#include <string>
#include <cstdint>

std::string convert_to_radix(uint64_t decimal_number, uint8_t radix) {
    if (radix < 2 || radix > 36) {
        throw std::invalid_argument("Radix must be between 2 and 36.");
    }

    if (decimal_number == 0) {
        return "0";
    }

    std::stack<uint64_t> remainders;
    std::string result;

    // Convert the number to the desired base by dividing and storing remainders.
    while (decimal_number > 0) {
        remainders.push(decimal_number % radix);
        decimal_number /= radix;
    }

    // Convert remainders to characters and build the result string.
    while (!remainders.empty()) {
        uint64_t top_element = remainders.top();

        // If the remainder is greater than 9, it corresponds to a letter
        // (A-Z for radixs > 10)
        char digit = top_element > 9 ? top_element + 55 : top_element + 48;
        result.push_back(digit);
        remainders.pop();
    }

    return result;
}
