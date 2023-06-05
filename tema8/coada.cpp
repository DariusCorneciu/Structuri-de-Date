#include <iostream>
#include <vector>

class Coada {
private:
    std::vector<int> coada;
    int capat_inserare;
    int capat_extragere;

public:
    Coada() {
        coada.resize(100); // Inițializăm dimensiunea vectorului la 100
        capat_inserare = 0;
        capat_extragere = 0;
    }

    bool isEmpty() {
        return capat_inserare == capat_extragere;
    }

    bool isFull() {
        return capat_inserare - capat_extragere >= 100;
    }

    void enqueue(int element) {
        if (!isFull()) {
            coada[capat_inserare % 100] = element;
            capat_inserare++;
        } else {
            std::cout << "Coada este plină." << std::endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int element = coada[capat_extragere % 100];
            capat_extragere++;
            return element;
        } else {
            std::cout << "Coada este goală." << std::endl;
            return -1; // Sau puteți arunca o excepție în loc să returnați o valoare arbitrară.
        }
    }
};
