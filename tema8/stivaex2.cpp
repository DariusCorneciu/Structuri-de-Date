#include <iostream>
using namespace std;
struct Nod {
    int valoare;
    Nod* urmator;

    Nod(int val) : valoare(val), urmator(nullptr) {}
};

class Stiva {
private:
    Nod* varf;

public:
    Stiva() : varf(nullptr) {}

    bool empty() {
        return varf == nullptr;
    }

    void push(int element) {
        Nod* nou = new Nod(element);
        nou->urmator = varf;
        varf = nou;
    }

    int pop() {
        if (!empty()) {
            Nod* nod_sters = varf;
            int element = nod_sters->valoare;
            varf = varf->urmator;
            delete nod_sters;
            return element;
        } else {
            cout << "Stiva este goala." << endl;
            return -1;
        }
    }

    int peek() {
        if (!empty()) {
            return varf->valoare;
        } else {
            cout << "Stiva este goala." << endl;
            return -1;
        }
    }

    int search(int element) {
        Nod* nod_curent = varf;
        int distanta = 0;
        while (nod_curent != nullptr) {
            if (nod_curent->valoare == element) {
                return distanta;
            }
            nod_curent = nod_curent->urmator;
            distanta++;
        }
        return -1;
    }

    void afisare() {
        Nod* nod_curent = varf;

        if(empty()){
            cout<<"Stiva vida"<<endl;
        }else{
            cout << "Varf -> ";
            while (nod_curent != nullptr) {
                cout << nod_curent->valoare << " -> ";
                nod_curent = nod_curent->urmator;
            }
            cout << "Baza" << endl;
        }

    }
};
int main(){
    Stiva a;
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
