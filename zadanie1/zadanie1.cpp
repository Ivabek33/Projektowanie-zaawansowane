#include <iostream>

// Struktura reprezentująca węzeł listy dwukierunkowej
struct Node {
    int data;       // Przechowywane dane
    Node* prev;     // Wskaźnik na poprzedni węzeł
    Node* next;     // Wskaźnik na następny węzeł

    // Konstruktor węzła
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Klasa reprezentująca listę dwukierunkową
class DoublyLinkedList {
private:
    Node* head;     // Wskaźnik na pierwszy węzeł listy
    Node* tail;     // Wskaźnik na ostatni węzeł listy

public:
    // Konstruktor listy dwukierunkowej
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

};

int main()
    {
        return 0;
    }