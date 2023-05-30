#include <iostream>
#include <list>

using namespace std;

void display(list<int> l){
    for(int i:l){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    display(l);

    //l.erase(l.begin());
    //display(l);

    l.size(); // returns the size of the list
    // copy list l to list n
    list <int> n(l);
    display(n);

    list <int> m(5,69);
    display(m);

    return 0;
}