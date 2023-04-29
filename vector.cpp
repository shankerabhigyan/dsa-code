#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    cout<<"Capacity: "<<v.capacity()<<endl;
    v.push_back(10);
    cout<<"Capacity: "<<v.capacity()<<endl;
    v.push_back(20);
    cout<<"Capacity: "<<v.capacity()<<endl;
    v.push_back(30);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;

    //element at index 1
    cout<<"Element at index 1: "<<v.at(1)<<endl;

    v.pop_back();
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;

    //initialise vector with size 10 and all values as 5
    vector<int> v2(10,5);
    cout<<"Vector v2: ";
    for (int i: v2)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    return 0;
}

// vectors are stored in contiguous memory locations
// so accessing elements is faster
// insertion and deletion is slower as compared to list
// insertion and deletion at the end is faster compared to deque and list as it does not involve shifting of elements
// insertion and deletion at the middle is slower as compared to list as it involves shifting of elements
// random access is faster as compared to list and deque as it uses indexing

//deletion and insertion can be done at the end of the vector in O(1) time