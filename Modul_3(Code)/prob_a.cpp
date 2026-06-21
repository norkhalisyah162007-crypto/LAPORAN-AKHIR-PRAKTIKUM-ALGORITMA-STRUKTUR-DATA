#include <iostream>
#include "single_linked_list.h"
using namespace std;

int main() {
    SingleLinkedList sll;
    sll.init();

    int N;
    long long K;
    cin >> N >> K;
    long long awalK = K;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        sll.add_back(x);
    }

    Node* current = sll.tail;

    while (sll.size > 1){
        long long langkah = K % sll.size;

        if (langkah == 0) langkah = sll.size;

        Node* prev = current;

        for (long long i = 0; i < langkah - 1; i++){
            prev = prev -> next;
        }

        Node* target = prev -> next;
        int nilai = target -> data;

        if (target == sll.head){
            sll.head = target -> next;
            sll.tail -> next = sll.head;
        } else if (target == sll.tail){
            sll.tail = prev;
            sll.tail -> next = sll.head;
        } else {
            prev -> next = target -> next;
        }

        delete target;
        sll.size--;
        current = prev;
        if (nilai % 2 == 0) K++;
        else K--;
        if (K <= 0) K = awalK;
    }

    cout << sll.head -> data << endl;
    sll.clear();

    return 0;
}