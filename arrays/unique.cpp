#include<iostream>
using namespace std;
//2m+1 elements in array
//m numbers appear twice one number is unique
//find the unique number

int unique(int arr[],int size){
    int uni = 0;
    for(int i=0;i<size;i++){
        uni = uni^arr[i];
    }
    return uni;

}

int main(){
    int m;
    cout<<"Enter value of m: ";
    cin>>m;
    int size = 2*m+1;

    int arr[size];
    cout<<"Enter array of "<< size << " elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Unique number is: "<<unique(arr,size)<<endl;
    return 0;
}