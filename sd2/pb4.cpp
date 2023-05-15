#include <iostream>
using namespace std;

const int n2 = 1e3;
int v[n2],n;

void citire()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

int main()
{
    citire();
    int elementu = 0;
    for(int i = 0; i < n; i++)
    {
        elementu = elementu ^ v[i];
    }
    cout << elementu;
}//
// Created by Darius Corneciu on 5/16/2023.
//
