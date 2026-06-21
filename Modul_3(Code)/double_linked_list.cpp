#include <iostream>
#include <stdexcept>
#include "double_linked_list.h"
using namespace std;

void DoubleLinkedList::init(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty(){
    return head == nullptr;
}

void DoubleLinkedList::add_front(char val){
    Node* baru = new Node;
    baru->data = val;
    if (is_empty()) {
        baru->next = baru;
        baru->prev = baru;
        head = baru;
        tail = baru;
    }
    else {
        baru->next = head;
        baru->prev = tail;
        head->prev = baru;
        tail->next = baru;
        head = baru;
    }
    size++;
}

void DoubleLinkedList::add_back(char val){
    Node* baru = new Node;
    baru->data = val;
    if (is_empty()) {
        baru->next = baru;
        baru->prev = baru;
        head = baru;
        tail = baru;
    }
    else {
        baru->prev = tail;
        baru->next = head;
        tail->next = baru;
        head->prev = baru;
        tail = baru;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx){
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
    for (int i = 0; i < idx - 1; i++){
        temp = temp->next;
    }
    Node* baru = new Node;
    baru->data = val;
    baru->next = temp->next;
    baru->prev = temp;
    temp->next->prev = baru;
    temp->next = baru;
    size++;
}

void DoubleLinkedList::delete_front(){
    if (is_empty()){
        throw out_of_range("List kosong");
    }
    Node* hapus = head;
    if (head == tail){
        head = nullptr;
        tail = nullptr;
    }
    else{
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete hapus;
    size--;
}

void DoubleLinkedList::delete_back(){
    if (is_empty()){
        throw out_of_range("List kosong");
    }
    if (head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    Node* hapus = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete hapus;
    size--;
}

void DoubleLinkedList::delete_idx(int idx){
    if (is_empty()){
        throw out_of_range("List kosong");
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
    for (int i = 0; i < idx; i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}

void DoubleLinkedList::display(){
    if (is_empty()) {
        cout << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

char DoubleLinkedList::get(int idx){
    if (is_empty()){
        throw out_of_range("List kosong");
    }
    if (idx < 0 || idx >= size){
        throw out_of_range("Index out of range");
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++){
        temp = temp->next;
    }
    return temp->data;
}

void DoubleLinkedList::set(char val, int idx){
    if (is_empty()) {
        throw out_of_range("List kosong");
    }
    if (idx < 0 || idx >= size){
        throw out_of_range("Index out of range");
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++){
        temp = temp->next;
    }
    temp->data = val;
}

void DoubleLinkedList::clear(){
    if (is_empty()) return;
    Node* cur = head;
    tail->next = nullptr;
    while (cur != nullptr){
        Node* hapus = cur;
        cur = cur->next;
        delete hapus;
    }
    head = tail = nullptr;
    size = 0;
}