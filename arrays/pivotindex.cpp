// find the pivot index of an array
// https://leetcode.com/problems/find-pivot-index/
// pivot index is the index where the sum of elements to the left and right are strictly equal
// input is a sorted and rotated array eg. [13,15,1,6,10,12] --> pivot index is 2
// note: if index is on the left/right edge, the sum of that side is 0
//  return leftmost pivot index else return -1


#include <iostream>
using namespace std;

int pivotIndex(int arr[], int size){
    int pivot = -1;


    return pivot;
}

int main(){
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "The pivot index is: " << pivotIndex(arr, size) << endl;

    return 0;
}