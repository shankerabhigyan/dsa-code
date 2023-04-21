#include<iostream>
using namespace std;
//to-do : implement for decreasing order array and for non-sorted array
int binarySearch(int arr[], int size, int element){
    int start = 0;
    int end = size-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==element){
            return mid;
        }
        else if(arr[mid]>element){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return 404;
}

int main(){
    cout << "Input array size" << endl;
    int size;
    cin >> size;
    int arr[size];
    cout <<  "Input array elements in increasing"<< endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    cout << "Input element to search"<< endl;
    int element=0;
    cin >> element;
    int index = binarySearch(arr, size, element);

    cout<< "Element found at index: " << index << endl;

    return 0;
}