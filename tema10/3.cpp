#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    // Declarați o coadă de priorități (min-heap) care conține perechi (valoare, prioritate)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    pq.push({2, 3});
    pq.push({1, 2});
    pq.push({4, 1});
    pq.push({3, 2});


    pair<int, int> topElement = pq.top();
    cout << "Top element: (" << topElement.first << ", " << topElement.second << ")" << endl;


    pq.pop();


    while (!pq.empty()) {
        pair<int, int> element = pq.top();
        cout << "Element: (" << element.first << ", " << element.second << ")" << endl;
        pq.pop();
    }

    return 0;
}
