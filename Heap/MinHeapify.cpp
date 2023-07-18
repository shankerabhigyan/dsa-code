#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

void MinHeapify(vector<int> &arr, int i, int heapSize){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;

    if(l<heapSize && arr[l]<arr[smallest]){
        smallest = l;
    }
    if(r<heapSize && arr[r]<arr[smallest]){
        smallest = r;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        MinHeapify(arr, smallest, heapSize);
    }
}

vector<int> buildMinHeap(vector<int> &arr){
    int size = arr.size();
    for(int i=size/2 -1; i>=0; i--){
        cout << i << endl;
        MinHeapify(arr,i,size);
    }

    return arr;
}

int main(){

    vector<int> v = {9, 3, 2, 6, 7};
    vector<int> arr = buildMinHeap(v);

    for(auto x:arr){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}