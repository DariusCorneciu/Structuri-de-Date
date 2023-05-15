#include <iostream>
using namespace std;

const int n2 = 1e3;
int v[n2],n,k;
bool noexist = true;

void citire()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> v[i];
    }
}

int main()
{
    citire();
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        if (v[i] != k)
        {
            v[m++] = v[i];
        }
        else {
            noexist = false;
        }
    }
    n = m;
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    if(noexist)
    {
        cout << "Nu exista " << k;
    }
}