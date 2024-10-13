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

    // Wyświetlanie listy od początku
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Dodawanie elementów na początku listy
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    // Wyświetlanie listy od początku
    std::cout << "Lista dwukierunkowa: ";
    list.displayForward();

    return 0;
}