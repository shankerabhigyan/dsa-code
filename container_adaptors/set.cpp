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
    set <int> :: iterator it = s.begin(); // iterator to the first element of the set
    s.erase(++it); 
    display(s); 
    // the complexity of erase is O(log(n)) since it uses find() internally
    // ************************************
    //s.count() returns 1 if the element is present in the set else returns 0
    cout << s.count(15) << endl; // returns 1
    cout << s.count(20) << endl; // returns 1
    return 0;
}