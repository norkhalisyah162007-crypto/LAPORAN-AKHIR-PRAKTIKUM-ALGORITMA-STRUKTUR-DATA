#include "stack.h"
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        std::string token;
        std::cin >> token;

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);
            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else result = a / b;
            push(&s, result);
        } else {
            push(&s, std::stoi(token));
        }
    }

    std::cout << peek(&s) << std::endl;
    return 0;
}
