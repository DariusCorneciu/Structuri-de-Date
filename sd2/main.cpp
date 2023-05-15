#include <iostream>
using namespace std;
const int n2 = 1e3;
const int INF = 1000000;
int n,v[n2],minim = INF,maxim;




void minmax(int v[],int st,int dr)
{
    if (dr - st <= 1)
    {
        minim = min(minim, min(v[st], v[dr]));
        maxim = max(maxim, max(v[st], v[dr]));
        return;
    }
    int mij = (st+dr) / 2;
    minmax(v,st,mij);
    minmax(v,mij+1,dr);
}

void citire_vector()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}
int main() {
    citire_vector();
    minmax(v, 0, n-1);
    cout << minim << " " << maxim;

    return 0;
}
