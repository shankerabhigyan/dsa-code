#include<bits/stdc++.h>
using namespace std;
// set is a container that stores unique elements following a specific order.

void display(set <int> s){ //auto is used to automatically detect the data type of the variable that is being iterated
    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    s.insert(15); // this will not be inserted as set stores unique elements only
    // the complexity of insert is O(log(n)) since it uses find() internally
    display(s); 

    // ***********************************
    // s.find(x) returns the iterator to the element x if it is found else returns the iterator to the end of the set
    int x;
    cout << "Find element: ";
    cin >> x;
    // complexity of find is Olog(n) since it is based on binary search
    if (s.find(x) !=s.end()){
        cout << "Element found" << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    // ************************************

    s.erase(15); // this will erase the element 15 from the set
    // the complexity of erase is O(log(n)) since it uses find() internally

    return 0;
}