// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include<bits/stdc++.h>
using namespace std;

void MaxHeapify(vector<int> &v, int i, int heapSize){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if(l<heapSize && v[l]>v[largest]){
        largest = l;
    }
    if(r<heapSize && v[r]>v[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(v[i],v[largest]);
        MaxHeapify(v, largest, heapSize);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){
    vector<int> v(m+n);
    int heapSize = m+n;
    int i=0;
    for(int x:a){
        v[i] = x;
        i++;
    }

    for(int x:b){
        v[i] = x;
        i++;
    }

    for(int i=heapSize/2 -1; i>=0; i--){
        MaxHeapify(v,i,heapSize);
    }
    return v;
}

int main(){
    vector<int> a = {6};
    vector<int> b = {17};
    vector<int> v = mergeHeaps(a,b,1,1);
    for(auto x:v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}