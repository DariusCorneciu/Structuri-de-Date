#include <iostream>
#include <vector>
using namespace std;

class NodArbobe {
public:
    int data;
    NodArbobe* stang;
    NodArbobe* drept;

    NodArbobe(int value) {
        data = value;
        stang = nullptr;
        drept = nullptr;
    }
    ~NodArbobe(){
        if(stang != nullptr){delete stang;}
        if(drept != nullptr){delete drept;}
    }
};

class Arbore {
private:
    NodArbobe* root;

    NodArbobe* insertNode(NodArbobe* currentNode, int value) {
        if (currentNode == nullptr) {
            return new NodArbobe(value);
        }

        if (value < currentNode->data) {
            currentNode->stang = insertNode(currentNode->stang, value);
        } else if (value > currentNode->data) {
            currentNode->drept = insertNode(currentNode->drept, value);
        }

        return currentNode;
    }

    void printInOrder(NodArbobe* currentNode) {
        if (currentNode != nullptr) {
            printInOrder(currentNode->stang);
            std::cout << currentNode->data << " ";
            printInOrder(currentNode->drept);
        }
    }

public:
    Arbore() {
        root = nullptr;
    }

    void insertvector(vector<int> vector1){
        for(auto i = vector1.begin();i<vector1.end();i++){
            insert(*i);
        }
    }
    void insert(int value) {
        root = insertNode(root, value);
    }

    void print() {
        printInOrder(root);
    }
};



int main() {
    Arbore arborebinar;

    arborebinar.insertvector(vector<int>{5,3,7,2,4,6,8});
    arborebinar.print();

    return 0;
}