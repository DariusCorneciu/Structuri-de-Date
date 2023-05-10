#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
ifstream f("C:\\Users\\Darius Corneciu\\CLionProjects\\SD1\\input.txt");

int min_max(int start, int coada,int v[])
{
    int min,max;

    if (start==coada)
    {
        min=v[start];
        max=v[start];
    }
    else if (start+1==coada)
    {
        if(v[start]>v[coada])
            min=v[coada],max=v[start];
        else
            min=v[start],max=v[coada];
    }
    else
    {
        int mijloc= start + (start+coada)/2;
        int stanga[2] = min_max(start,mijloc,v);
        int dreapta[2] = min_max(mijloc+1,coada,v);
        if (stanga[0] > dreapta[0])
            max=stanga[0];
        else
            max=dreapta[0];
        if (stanga[1]< dreapta[1])
            min=stanga[1];
        else
            min=dreapta[1];
    }
    int ras[2]={min,max};
    return ras;

}
int main() {

    int n,vec[10001];
    f>>n;
    for(int i=0;i<n;i++)
        f>>vec[i];
    return 0;
}
