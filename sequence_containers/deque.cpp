#include <iostream>
#include <deque>
using namespace std;

void display(deque<int> d){
    for(int i:d){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    display(d);

    //d.pop_back();
    //display(d);

    //d.pop_front();
    //display(d);

    cout << d.at(1) << endl;
    cout << d.empty() << endl;
    
    d.erase(d.begin(),d.begin()+1); //d.begin() gives the address of the first element
    display(d);
    // even after erase operation the max memory alloted stays the same


    return 0;
}