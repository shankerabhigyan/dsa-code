// find peak index in a mountain array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/
// target time complexity => O(logn)

#include<iostream>
using namespace std;

int peak(int arr[], int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    while(! arr[mid]>arr[mid-1] && ! arr[mid]>arr[mid+1]){
        mid = start + (end-start)/2;
        if(arr[mid]>arr[mid-1]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }

    }
    return mid;
}


int main(){

    int size = 0;
    cout << "Input array size" << endl;
    cin >> size;
    int arr[size];
    cout <<  "Input array elements in mountain pattern"<< endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    int peakIndex = peak(arr, size);
    cout << "Peak index: " << peakIndex << endl;

    return 0;
}