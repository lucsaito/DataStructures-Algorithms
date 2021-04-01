//
// Created by Lucas on 05/03/21.
// This algorithm checks whether a sequence of brackets are correct or not
//

#include <iostream>
#include <string>
#include <vector>

std::string ReadInput() {
    std::string seq;
    std::cin >> seq;
    return seq;
}

char OppositeSymbol(const char symbol) {
    switch (symbol) {
        case '}':
            return '{';
            break;
        case ')':
            return '(';
            break;
        case ']':
            return '[';
            break;
        default:
            return '0';
    }
}

bool SequenceChecker(const std::string& sequence) {
    std::vector<char> stack;

    for (size_t i = 0; i < sequence.size(); i ++) {
        if (sequence[i] == '}' || sequence[i] == ']' || sequence[i] ==')') {
            if (stack.empty()) {
                return false;
            } else {
                char last_element = stack.back();
                stack.pop_back();
                if (last_element != OppositeSymbol(sequence[i])) {
                    return false;
                }
            }
        } else {
            stack.push_back(sequence[i]);
        }
    }
    return true;
}

int main() {
    std::string sequence = ReadInput();
    bool result = SequenceChecker(sequence);
    std::cout << result << std::endl;
    
    return 0;
}
