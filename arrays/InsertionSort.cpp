#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    int key,x;
    for(int i=1;i<n; i++){
        x = i-1;
        key = arr[i];
        while(x>=0){
            if(arr[x]>key){
                arr[x+1] = arr[x];
                arr[x] = key;
                x--;
            }
            else{
                break;
            }
        }
    }
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
    cout<<"Sorted array is: [ ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;

    return 0;
}