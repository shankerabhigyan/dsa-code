#include<bits/stdc++.h>
using namespace std;

 int* binarySearch(vector<int>v, int key){
    int n = v.size();
    vector<int>::iterator it;
    cout << "n : " << n << endl;
    if(n==1 || n==0){
        if(v[0]==key){
            int* ptr = &v[0];
            return ptr;
        }
        else{
            return NULL;
        }
    }
    int mid = n/2;
    if(v[mid]>key){
        vector<int> smallVector(v.begin(), v.begin() + mid);
        return binarySearch(smallVector,key);
    }
    else if(v[mid]<key){
        vector<int> smallVector(v.begin()+mid+1, v.end());
        return binarySearch(smallVector,key);
    }
    else{
        int* ptr = &v[mid];
        return ptr;
    }
}


int main(){
    vector<int> v;
    cout << "Enter size of array : ";
    int n;
    cin >> n;
    int x;
    while(n-- > 0){
        cin >> x;
        v.push_back(x);
    }

    cout << "Enter key to be searched : ";
    int key;
    cin >> key;
    int *ptr = binarySearch(v,key);
    if(ptr==NULL){
        cout << "Key not found" << endl;
    }
    else{
        cout << "Key found at " << ptr << endl;
    }

    return 0;
}