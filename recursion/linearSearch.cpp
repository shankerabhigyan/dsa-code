#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v, int n){
    if (n==0 || n==1){
        return true;
    }
    if(v[0]>v[1]){
        return false;
    }
    // point the vector pointer to next location using
    vector <int> smallVector(v.begin()+1,v.end()); 
    return isSorted(smallVector,n-1);
}

int linearSearch(vector<int> v, int key){
    int n = v.size();
    if(n==0){
        return -1;
    }
    if(v[0]==key){
        return n;
    }
    vector<int> smallVector(v.begin()+1,v.end());
    return linearSearch(smallVector,key);

}

int main(){
    vector<int> v;
    cout << "Enter size of the array: ";
    int n;
    cin >> n;
    int x;
    for (int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }
    //cout << isSorted(arr,n) << endl;
    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;
    int ls = linearSearch(v,key);
    if(ls==-1){
        cout << "Key not found" << endl;
    }
    else{
        cout << "Key found at index " << (n-ls) << endl;
    }

    return 0;
}