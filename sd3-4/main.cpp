#include <iostream>
using namespace std;
class node{
    int element;
    node *next;

public:
    node(){
        element = 0; next = nullptr;
    }
    node(node const &v): element(v.element),next(v.next){}

    node(int val, node *p){
        element = val;
        next = p;
    }
    ~node(){
        if(next != nullptr)
            delete next;
    }

    int getElement() const {
        return element;
    }

    void setElement(int element) {
        node::element = element;
    }

    node *getNext() const {
        return next;
    }

    void setNext(node *next) {
        this->next = next;
    }
};
class Lista{
    int size;
    node *prim,*ultim;

public:
    Lista(){
        size = 0; prim = nullptr; ultim = nullptr;
    }

    ~Lista() =default;
    void add_start(int valaore){
        if(prim == nullptr){
            prim = new node(valaore, nullptr);
            ultim = prim;
            size++;
        }
        else{
            node *next_prim = new node(valaore,prim);
            prim = next_prim;
            size++;
        }
    }
    void add_end(int valoare){
        if(prim == nullptr){
            prim = new node(valoare, nullptr);
            ultim =prim;
            size++;
        }
        else{
            node *viitor_ultim = new node(valoare, nullptr);
            ultim->setNext(viitor_ultim);
            ultim = viitor_ultim;
            size++;
        }
    }
    int find_element_by_value(int valuare){
        node *point = prim;
        int i = 1;
        while(point!= nullptr){
            if(point->getElement() == valuare){return i;}
            point = point->getNext();
            i++;
        }
        return -1;
    }
    int finde_element_by_poz(int pozitie){
        node *point = prim;
        int i = 1;
        if(pozitie > size or pozitie < 1){return -1;}
        if(pozitie == size){return ultim->getElement();}

        while(point!= nullptr){
            if(i == pozitie){return point->getElement();}
            i++;
            point = point->getNext();
        }
        return -1;
    }
    void insert_after_value(int looking_value,int insert_value){
        node *point = prim;
        int ok = 0;
        while(point != nullptr){
            if(point->getElement() == looking_value){
                if(point->getNext() == nullptr) {
                    add_end(insert_value);
                    ok = 1;
                }
                else{
                    ok = 1;
                    node *insert = new node(insert_value,point->getNext());
                    point->setNext(insert);
                    size++;
                }
                break;
            }
            point = point->getNext();
        }
        if(ok == 0){cout<<"Nu exista "<<looking_value<<" in lista.\n";}
    }
    void insert_in_specific_poz(int poz,int value){
        if(poz < 0 or poz > size){cout<<"Nu exista pozitia "<<poz<<" in lista.\n";}
        else if(poz == 1){add_start(value);}
        else if(poz == size){add_end(value);}
        else{
            node *point = prim->getNext();
            int i = 2;
            while(point != nullptr){
                if(i == poz){
                    node *insert = new node(value,point->getNext());
                    point->setNext(insert);
                    size++;
                    break;
                }
                point = point->getNext();
            }
        }

    }
    void delete_element_by_value(int looking_value){
        if(prim == nullptr){cout<<"Nu poti sa stergi din lista vida\n";}
        else if(size == 1){prim = nullptr; ultim = nullptr;size--;}
        else if(prim->getElement() == looking_value){
            node *viitor_prim = new node(prim->getNext()->getElement(),prim->getNext()->getNext());
            prim =viitor_prim;
            size --;
        }
        else{
            node *point = prim;
            while(point->getNext() != nullptr){
                if(point->getNext()->getElement() == looking_value){
                    if(point->getNext() == ultim){
                        ultim = point;
                    }
                    point->setNext(point->getNext()->getNext());
                    size--;
                    break;
                }


                point = point ->getNext();
        }


        }
    }
    void delete_element_by_poz(int poz){
        if(poz < 1 or poz > size){cout<<"Nu exista pozita pe care vrei sa stergi!\n";}
        if(poz == 1){
            if(size == 1){
                prim = nullptr; ultim = nullptr;size--;
            }
            else{
                node *viitor_prim = new node(prim->getNext()->getElement(),prim->getNext()->getNext());
                prim = viitor_prim;
                size --;
            }
        }
        else {
            int i=2;
            node *point = prim;
            while(point->getNext() != nullptr){
                if(i == poz){
                    if(point->getNext() == ultim){
                        ultim = point;
                    }
                    point->setNext(point->getNext()->getNext());
                    size--;
                    break;
                }

                i++;
                point = point ->getNext();
            }


        }
    }
    friend ostream & operator << (ostream &out, const Lista &v);
    friend istream  & operator  >>(istream &in, Lista &v);

};
ostream & operator<<(ostream &out,const Lista &v){
 /// nu merge cu . ca e pointer si . = ->
    if(v.size == 0)
        out<<"Lista vida\n";
    else{
        node *point = new node(v.prim->getElement(),v.prim->getNext());
        while(point!= nullptr){
            out<<point->getElement()<<" ";
            point = point->getNext();
        }
        cout<<endl;
        cout<<"Prim: "<<v.prim->getElement()<<endl;
        cout<<"Ultim: "<<v.ultim->getElement()<<endl;
        cout<<"Size: "<<v.size<<endl;
    }



}


istream  & operator>>(istream &in,Lista &v){
    int ele;
    cout << "Citeste marimea: "; in >> v.size;
    cout << "Citeste elementele";
    in >> ele;
    v.prim->setElement(ele);
    ///??;
}

int main() {
    Lista v;
    cout<<v;
   v.add_start(5);
   v.add_start(6);
   v.add_start(7);

   v.add_end(8);
   v.insert_after_value(6,9);
    cout<<v.find_element_by_value(8)<<endl;
    v.delete_element_by_value(6);
    v.delete_element_by_poz(1);
    cout<<v;
    return 0;
}
