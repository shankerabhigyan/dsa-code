#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &v){ // complexity = O(nlogn)
    // base case
    if(v.size()==0 || v.size()==1){ // already sorted
        return;
    } 
    // partition
    int pivot = v[0];
    vector<int> v1,v2;
    for(int i=1;i<v.size();i++){ 
        if(v[i]<pivot){
            v1.push_back(v[i]); // v1 contains elements less than pivot
        }
        else{
            v2.push_back(v[i]); // v2 contains elements greater than pivot
        }
    }
    // recursive calls
    quickSort(v1);
    quickSort(v2);
    // merge
    v.clear();
    for(int i=0;i<v1.size();i++){
        v.push_back(v1[i]);
    }
    v.push_back(pivot);
    for(int i=0;i<v2.size();i++){
        v.push_back(v2[i]);
    }
    
}

int main(){
    int x,n; 
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }

    quickSort(v);
    cout << "Sorted array: ";
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}