#include<iostream>
using namespace std;

int binarySearch(int arr[], int size){
    return 0;
}

int main(){
    cout >> "Input array size";
    int size;
    cin << size;
    int arr[size];
    cout >> "Input array elements";
    for(int i=0; i<size; i++){
        cin << arr[i];
    }
    cout >> "Input element to search";
    int element;
    cin << element;
    int index = binarySearch(arr, size, element);

    cout<< "Element found at index: " << index;

    return 0;
}