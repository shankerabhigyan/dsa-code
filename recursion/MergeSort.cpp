#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
    vector<int> v;
    int i=0,j=0;
    
}

vector<int> mergeSort(vector<int> v){
    int n = v.size();
    int mid = n/2;
    vector<int> v1(v.begin(), v.begin()+mid); // v1 = v[0...mid-1]
    vector<int> v2(v.begin()+mid, v.end()) // v2 = v[mid...n-1]

    if(n==0 || n==1){
        return v;
    }
    mergeSort(v1);
    mergeSort(v2);

    merge(v1, v2);
}

int main(){
    int x,n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }


    return 0;
}