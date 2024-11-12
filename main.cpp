#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

template <typename T>
class StringManipulator {
public:
    static std::string toUpperCase(const T& input) {
        std::string str = toString(input);
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }

    static std::string toLowerCase(const T& input) {
        std::string str = toString(input);
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    static std::string reverse(const T& input) {
        std::string str = toString(input);
        std::reverse(str.begin(), str.end());
        return str;
    }

    static std::string concatenate(const T& input1, const T& input2) {
        return toString(input1) + toString(input2);
    }

private:
    static std::string toString(const T& input) {
        if constexpr (std::is_same_v<T, std::string>) {
            return input;
        } else {
            return std::to_string(input);
        }
    }
};

int main() {
    StringManipulator<std::string> manipulator;
    std::string str = "Hello, World!";
    std::cout << "Original: " << str << std::endl;
    std::cout << "Uppercase: " << manipulator.toUpperCase(str) << std::endl;
    std::cout << "Lowercase: " << manipulator.toLowerCase(str) << std::endl;
    std::cout << "Reversed: " << manipulator.reverse(str) << std::endl;
    std::cout << "Concatenated: " << manipulator.concatenate(str, " C++") << std::endl;

    return 0;
}
