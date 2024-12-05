#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/quick-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-sort

class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low>=high) return;
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
        return;
    }

    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = low; // future pivot index | currently @ low
        int i = low;
        int j = high;

        while(i<j){
            while(i<high && arr[i]<=arr[pivot]){
                i++;
            }
            while(j>low && arr[j]>=arr[pivot]){
                j--;
            }
            if(i<j) swap(arr[i],arr[j]);
        }
        swap(arr[pivot],arr[j]);
        return j;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sol.quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}