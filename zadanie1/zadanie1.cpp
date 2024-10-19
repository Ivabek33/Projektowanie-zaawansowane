﻿#include <iostream>

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

    // Dodawanie elementu na początku listy
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Tworzenie nowego węzła
        if (head == nullptr) {           // Jeśli lista jest pusta
            head = tail = newNode;       // Head i tail wskazują na nowy węzeł
        }
        else {
            newNode->next = head;        // Nowy węzeł wskazuje na obecny head
            head->prev = newNode;        // Obecny head wskazuje na nowy węzeł jako prev
            head = newNode;              // Aktualizacja head do nowego węzła
        }
    }

    // Dodawanie elementu na końcu listy
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Tworzenie nowego węzła
        if (tail == nullptr) {           // Jeśli lista jest pusta
            head = tail = newNode;       // Head i tail wskazują na nowy węzeł
        }
        else {
            tail->next = newNode;        // Ostatni węzeł wskazuje na nowy węzeł
            newNode->prev = tail;        // Nowy węzeł wskazuje na stary tail
            tail = newNode;              // Aktualizacja tail do nowego węzła
        }
    }

    // Wyświetlanie listy od początku
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Usuwanie całej listy
    void deleteList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next; // Zapisanie wskaźnika na następny węzeł
            std::cout << "Usuwanie wezla o wartości: " << current->data << std::endl;
            delete current;             // Zwalnianie obecnego węzła
            current = next;             // Przechodzenie do następnego węzła
        }
        head = tail = nullptr;           // Resetowanie wskaźników po usunięciu listy
    }

    // Dodawanie elementu pod wskazany indeks
    void insertAtIndex(int value, int index) {
        if (index == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp == tail) {
            insertAtEnd(value);
        }
        else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    // Destruktor listy dwukierunkowej
    ~DoublyLinkedList() {
        deleteList(); // Usuwanie całej listy przy niszczeniu obiektu
    }
};

int main() {
    DoublyLinkedList list;

    // Dodawanie elementów na początku listy
    list.insertAtBeginning(33);
    list.insertAtBeginning(27);
    list.insertAtBeginning(14);
    

    // Dodawanie elementów na końcu listy
    list.insertAtEnd(99);
    list.insertAtEnd(73);

    // Dodawanie elemetu pod wskazany indeks
    list.insertAtIndex(54, 2);

    // Wyświetlanie listy od początku
    std::cout << "Lista dwukierunkowa: ";
    list.displayForward();

    // Usuwanie całej listy
    std::cout << "Usuwanie calej listy:" << std::endl;
    list.deleteList();

    return 0;
}