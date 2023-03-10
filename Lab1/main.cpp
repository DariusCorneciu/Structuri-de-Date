#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
ifstream f("C:\\Users\\Darius Corneciu\\CLionProjects\\SD1\\input.txt");

void interschimbare(int &a,  int &b)
{
    int aux;
    aux=a;
    a=b;
    b=aux;
}

void bubblesort(int n, int v[])
{
    int i,j,aux;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(v[j]>v[j+1])
            {
                interschimbare(v[j],v[j+1]);
            }
}

void insertionsort(int n,int v[])
{
    int i,j;
    for(i=1;i<n;i++)
    {
        j=i;
        while(j>0 and v[j-1]>v[j])
        {
            interschimbare(v[j],v[j-1]);
            j--;

        }
    }
}

void selectionsort(int n,int v[])
{
    int i,j,poz;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(v[i]>v[j])
                interschimbare(v[i],v[j]);



}

int cautare_secventiala(int x,int n, int v[])
{
    int poz=-1,i;
    for(i=0;i<n;i++)
        if(v[i]==x)
        {
            poz=i;
            break;
        }

    return poz;
}

int cautare_binara(int x,int n, int v[])
{
    int stanga=0,dreapta=n,mijloc;

    while(dreapta>=stanga)
    {
        mijloc=(dreapta+stanga)/2;
        if(v[mijloc]==x)
            return mijloc;
        if(v[mijloc]>x)
            dreapta=mijloc-1;
        else
            stanga=mijloc+1;

    }
    return -1;


}

int menu_sort()
{
    int alege;
    cout<<"Alege tipul de sortare:";
    while(alege!=1 and alege!=2 and alege!=3)
    {
        cin>>alege;
        if(alege!=1 and alege!=2 and alege!=3)
            cout<<"Eroare, alege alt numar: ";
    }
    return alege;

}

int main() {

    int n,vec[10001],alege;
    clock_t start,end;
    f>>n;
    for(int i=0;i<n;i++)
        f>>vec[i];
    alege=menu_sort();
    start=clock();
    if(alege==1)
        cout<<"Bubble Sort",bubblesort(n,vec);
    else if (alege==2)
        cout<<"Insertion Sort",insertionsort(n,vec);
    else
        cout<<"Selection Sort",selectionsort(n,vec);
    end=clock();
    double timp=double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"Timp: "<<fixed<<timp<<" sec"<<endl;

    cout<<cautare_binara(10,n,vec)<<endl;
    cout<<cautare_secventiala(20,n,vec);
    return 0;
}
