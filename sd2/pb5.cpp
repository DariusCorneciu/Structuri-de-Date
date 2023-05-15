#include <iostream>
using namespace std;

const int n = 1e3 + 1;
int P[n],Q[n],P_Q[n], t,grad_Q, grad_P;

void citire_polinom(int P[], int& grad_polinom)
{
    cout << "Care este gradul polinomului?\n";
    cin >> grad_polinom;
    for(int i = grad_polinom - 1 ; i >= 0; i--)
    {
        cin >> P[i];
    }
}

int putere(int x, int p)
{
    int result = x;
    for(int i = 0; i < p; i++)
    {
        result *= x;
    }
    return result;
}

int polinom(int P[], int grad_polinom, int t)
{
    int rez = P[0];
    for(int i = 1; i < grad_polinom; i++)
    {
        rez += P[i] * putere(t,i-1);
    }
    return rez;
}

void polinom(int P[], int Q[], int p, int q)
{
    int dim_P_Q = max(p,q);
    for(int i = 0; i < p; i++)
    {
        P_Q[i] = P[i];
    }
    for(int i = 0; i < q; i++)
    {
        P_Q[i] += Q[i];
    }
    for(int i = dim_P_Q-1; i >= 0; i--)
    {
        cout << P_Q[i] << " ";
    }
}

int main()
{
    citire_polinom(P, grad_P);
    cin >> t;
    citire_polinom(Q, grad_Q);
    cout << polinom(P, grad_P, t) << "\n";
    polinom(P, Q, grad_P, grad_Q);
    return 0;
}
