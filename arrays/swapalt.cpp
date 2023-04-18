#include<iostream>
using namespace std;
//swapping alternate elemnts of an array

void swaparr(int arr[], int size){
    for (int i=0; i<size-1; i+=2)
    {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}


int main(){

    int arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
    swaparr(arr, 11);
    for(int i=0; i<11; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}