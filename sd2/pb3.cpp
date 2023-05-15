#include <iostream>
using namespace std;

const int n2 = 1e3;
int v[n2],v2[n2],n,k,t;
bool exist;

void citire()
{
    cin >> n >> k >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void inserare_elem(int k,int t)
{
    int aux[n2];
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        aux[m++] = v[i];
        if (v[i] == k)
        {
            aux[m++] = t;
            exist = true;
        }
    }
    n = m;
    for(int i = 0; i < n; i++)
    {
        v[i] = aux[i];
    }
}

void inserare_vector(int k,int t)
{
    int aux[n2];
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        aux[m++] = v[i];
        if (v[i] == k)
        {
            exist = true;
            for(int j = 0; j < t; j++)
            {
                aux[m++] = v2[j];
            }
        }
    }
    n = m;
    for(int i = 0; i < n; i++)
    {
        v[i] = aux[i];
    }
}

void afisare()
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    if(!exist)
    {
        cout << k << "nu exista!";
    }
}

int main()
{
    citire();
    inserare_elem(k, t);
    afisare();
    return 0;
}