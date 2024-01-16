// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(vector<int> &arr, int i, int heapsize){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int maximum = i;

    if(l<heapsize && arr[l]>arr[maximum]){
        maximum = l;
    }
    if(r<heapsize && arr[r]>arr[maximum]){
        maximum = r;
    }

    if(maximum!=i){
        swap(arr[i],arr[maximum]);
        MaxHeapify(arr,maximum,heapsize);
    }
}

int getKthMinimumElement(vector<int>&arr, int k){
    // MaxHeapify
    int t = k;
    int heapsize = arr.size();
    for(int i=heapsize-1/2;i>=0;i--){
        MaxHeapify(arr,i,heapsize);
    }
    int ans=arr[0];
    while(t>1 && heapsize>0){
        swap(arr[0],arr[heapsize-1]);
        t--;
        heapsize--;
        MaxHeapify(arr, 0, heapsize);
        ans = arr[0];
    }
    return ans;
}

int main(){
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    int k;
    cin >> k;
    cout << "The "<< k << " largest element is : " << getKthMinimumElement() << endl;
    return 0;
}