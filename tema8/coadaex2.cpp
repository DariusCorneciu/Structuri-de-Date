#include <iostream>
using namespace std;
struct Nod {
    int valoare;
    Nod* urmator;

    Nod(int val) : valoare(val), urmator(nullptr) {}
};

class Coada {
private:
    Nod* inceput;
    Nod* sfarsit;

public:
    Coada() : inceput(nullptr), sfarsit(nullptr) {}

    bool empty() {
        return inceput == nullptr;
    }

    void push(int element) {
        Nod* nou = new Nod(element);
        if (empty()) {
            inceput = sfarsit = nou;
        } else {
            sfarsit->urmator = nou;
            sfarsit = nou;
        }
    }

    int pop() {
        if (!empty()) {
            Nod* nod_sters = inceput;
            int element = nod_sters->valoare;
            inceput = inceput->urmator;
            delete nod_sters;
            if (inceput == nullptr) {
                sfarsit = nullptr;
            }
            return element;
        } else {
            cout << "Coada este goala." << endl;
            return -1;
        }
    }

    int peek() {
        if (!empty()) {
            return inceput->valoare;
        } else {
            cout << "Coada este goala." << endl;
            return -1;
        }
    }

    int search(int element) {
        Nod* nod_curent = inceput;
        int numar_pop = 0;
        while (nod_curent != nullptr) {
            if (nod_curent->valoare == element) {
                return numar_pop+1;
            }
            nod_curent = nod_curent->urmator;
            numar_pop++;
        }
        return -1;
    }

    void afisare() {
        Nod* nod_curent = inceput;
        if(empty()){
            cout<<"coada vida"<<endl;
        }else{
            cout << "out -> ";
            while (nod_curent != nullptr) {
                std::cout << nod_curent->valoare <<' ';
                nod_curent = nod_curent->urmator;
            }
            cout << "in" << endl;
        }

    }
};

int main(){
    Coada a;
    a.afisare();
    a.push(1);
    a.push(2);
    a.push(3);
    a.afisare();
    cout<<a.search(2)<<endl;
    cout<<a.search(4)<<endl;
    cout<<a.empty()<<endl;
    cout<<a.pop()<<endl;
    a.afisare();
    cout<<a.peek();
    a.afisare();
    a.pop();
    a.pop();
    a.afisare();
    cout<<a.pop();
    cout<<a.empty();
}
