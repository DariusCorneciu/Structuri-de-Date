#include <iostream>
#include <vector>
using namespace std;

class Stiva {
private:
    vector<int> stiva;

public:
    bool isEmpty() {
        return stiva.empty();
    }

    void push(int element) {
        stiva.push_back(element);
    }

    int pop() {
        if (!isEmpty()) {
            int element = stiva.back();
            stiva.pop_back();
            return element;
        } else {
            cout << "Stiva este goală." << endl;
            return -1; // Sau puteți arunca o excepție în loc să returnați o valoare arbitrară.
        }
    }

    int peek() {
        if (!isEmpty()) {
            return stiva.back();
        } else {
            cout << "Stiva este goală." << endl;
            return -1; // Sau puteți arunca o excepție în loc să returnați o valoare arbitrară.
        }
    }
};

