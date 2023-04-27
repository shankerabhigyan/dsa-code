#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    int temp=0;
    for(int i=n-1;i>0;i--){
        for(int j=0; j<i; j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}

int main(){
    int n=0;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BubbleSort(arr,n);
    cout<<"Sorted array : [ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;

    return 0;
}