
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int value) {
        val = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque {
private:
    Node* stanga;
    Node* dreapta;

public:
    Deque() {
        stanga = nullptr;
        dreapta = nullptr;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (stanga == nullptr) {
            stanga = dreapta = newNode;
        } else {
            newNode->next = stanga;
            stanga->prev = newNode;
            stanga = newNode;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (dreapta == nullptr) {
            stanga = dreapta = newNode;
        } else {
            newNode->prev = dreapta;
            dreapta->next = newNode;
            dreapta = newNode;
        }
    }

    int pop_front() {
        if (stanga == nullptr) {
            cout << "Deque este goala!" << endl;
            return -1;
        }

        int value = stanga->val;
        Node* temp = stanga;
        stanga = stanga->next;

        if (stanga == nullptr) {
            dreapta = nullptr;
        } else {
            stanga->prev = nullptr;
        }

        delete temp;
        return value;
    }

    int pop_back() {
        if (dreapta == nullptr) {
            cout << "Deque este goala!" << endl;
            return -1;
        }

        int value = dreapta->val;
        Node* temp = dreapta;
        dreapta = dreapta->prev;

        if (dreapta == nullptr) {
            stanga = nullptr;
        } else {
            dreapta->next = nullptr;
        }

        delete temp;
        return value;
    }

    void print() {
        Node* currentNode = stanga;
        while (currentNode != nullptr) {
            cout << currentNode->val << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;

    deque.push_front(2);
    deque.push_front(1);
    deque.push_back(3);
    deque.push_back(4);

    deque.print();

    int frontValue = deque.pop_front();
    int backValue = deque.pop_back();

    cout << "Prima valuare: " << frontValue <<endl;
    cout << "Ultima valuare: " << backValue << endl;

    deque.print();

    return 0;
}