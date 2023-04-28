#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){

}

int main(){
    int n=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    InsertionSort(arr, n);
    cout<<"Sorted array is: [";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;

    return 0;
}