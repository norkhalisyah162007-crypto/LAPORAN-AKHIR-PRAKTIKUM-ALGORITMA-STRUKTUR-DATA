#include <iostream>
#include <stdexcept>
#include "single_linked_list.h"
using namespace std;

void SingleLinkedList::init(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty(){
    return head == nullptr;
}

void SingleLinkedList::add_front(int val){
    Node* baru = new Node;
    baru -> data = val;
    if (is_empty()){
        head = baru;
        tail = baru;
        tail -> next = head;
    } else {
        baru -> next = head;
        head = baru;
        tail -> next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val){
    Node* baru = new Node;
    baru -> data = val;
    if (is_empty()){
        head = baru;
        tail = baru;
        tail -> next = head;
    } else {
        baru -> next = head;
        tail -> next = baru;
        tail = baru;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx){
    if (idx < 0 || idx > size){
        throw out_of_range("Index out of range");
    }
    if (idx == 0){
        add_front(val);
        return;
    }
    if (idx == size){
        add_back(val);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < idx - 1 ; i++) {
        temp = temp -> next;
    }
    Node* baru = new Node;
    baru -> data = val;
    baru -> next = temp -> next;
    temp -> next = baru;
    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()){
        throw out_of_range("List Kosong");
    }
    Node* hapus = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head -> next;
        tail -> next = head;
    }
    delete hapus;
    size--;
}

void SingleLinkedList::delete_back(){
    if (is_empty()){
        throw out_of_range("List Kosong");
    }
    if (head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        size --;
        return;
    }
    Node* temp = head;
    while (temp -> next != tail){
        temp = temp -> next;
    }
    delete tail;
    tail = temp;
    tail -> next = head;
    size--;
}

void SingleLinkedList::delete_idx(int idx){
    if (is_empty()){
        throw out_of_range("List Kosong");
    }
    if (idx < 0 || idx >= size){
        throw out_of_range("Index out of range");
    }
    if (idx == 0){
        delete_front();
        return;
    }
    if (idx == size - 1){
        delete_back();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp -> next;
    }

    Node* hapus = temp -> next;
    temp -> next = hapus -> next;
    delete hapus;
    size--;
}

void SingleLinkedList::display(){
    if (is_empty()){
        return;
    }
    Node* temp = head;
    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while (temp != head);
    cout << endl;
}

int SingleLinkedList::get(int idx){
    if (is_empty()) {
        throw out_of_range("List Kosong");
    }
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp -> next;
    }
    return temp -> data;
}

void SingleLinkedList::set(int val, int idx){
    if (is_empty()) {
        throw out_of_range("List Kosong");
    }
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of range");
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp -> next;
    }
    temp -> data = val;
}

void SingleLinkedList::clear() {
    if (is_empty()) return;
    Node* cur = head;
    for (int i = 0; i < size; i++){
        Node* hapus = cur;
        cur = cur -> next;
        delete hapus;
    }
    head = tail = nullptr;
    size = 0;
}