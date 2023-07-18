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

void heapSort(vector<int> &v){
    int heapSize = v.size();
    for(int i = heapSize/2 -1; i>=0; i--){
        MaxHeapify(v,i,heapSize);
    }
    while(heapSize>1){
        swap(v[0],v[heapSize-1]);
        heapSize--;
        MaxHeapify(v, 0, heapSize);
    }
}

int main(){
    vector<int> v = {1,2,9,65,4,3,89,7,14};
    heapSort(v);
    for(auto x:v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}