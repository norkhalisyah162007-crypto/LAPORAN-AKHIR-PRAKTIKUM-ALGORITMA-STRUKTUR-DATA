#include "queue.h"
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int arr[100];
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    bool first = true;

    for (int i = 0; i <= n - k; i++) {
        Queue q;
        init(&q);
        for (int j = i; j < i + k; j++) enqueue(&q, arr[j]);

        int sum = 0;
        while (!isEmpty(&q)) {
            sum += front(&q);
            dequeue(&q);
        }

        if (!first) std::cout << " ";
        std::cout << sum;
        first = false;
    }

    std::cout << std::endl;
    return 0;
}
