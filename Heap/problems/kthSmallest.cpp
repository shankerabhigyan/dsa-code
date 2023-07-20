#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// APPROACH 1:

void MinHeapify(int* &arr, int i, int heapSize){
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

int kthSmallest(int* arr, int l, int r, int k){
    int heapSize = r+1;
    for(int i=heapSize/2 -1; i>=0; i--){
        MinHeapify(arr,i,heapSize);
    }

    int ans;

    while(k>0){
        swap(arr[0],arr[heapSize-1]);
        heapSize--;
        ans = arr[heapSize];
        MinHeapify(arr,0,heapSize);
        k--;
    }

    return ans;

} // l and r denote the starting and ending indices of the array

// APPROACH 2:

int KthSmallest(int arr[], int l, int r, int k){
    priority_queue<int> heap; // maxheap
    for(int i=0;i<k;i++){
        heap.push(arr[i]);
    }

    for(int i=k;i<r+1;i++){
        if(arr[i]<heap.top()){
            heap.pop();
            heap.push(arr[i]);
        }
    }

    return heap.top();
}

int main(){
    int k,n;
    cin >> n >> k;
    int* arr = new int[n];
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        arr[i] = x;
    }

    cout << n << endl;

    //int ans = kthSmallest(arr, 0, n-1, k);

    cout << ans << endl;

    delete(arr);

    return 0;
}