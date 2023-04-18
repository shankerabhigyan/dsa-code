#include<iostream>
#include<math.h>
using namespace std;

void printArray(int array[], int size){
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int maxmin(int arr[], int size, int &max, int &min){
    max = arr[0];
    min = arr[0];
    for(int i=0; i<size; i++){
        max = (arr[i] > max) ? arr[i] : max;
        min = (arr[i] < min) ? arr[i] : min;    
    
    return 0;
    }
}

void reverse(int arr[], int size){
    for(int i=0; i<size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int main(){
    
    int arr[17] = {0};
    //fill_n(arr, 17, 5);
    //cout << sizeof(arr)/sizeof(int) << endl;
    //cout << arr[6] << endl;
    printArray(arr, sizeof(arr)/sizeof(int));
    int arr1[17] = {100,5,9,134, 57, 67, 89, 34, 23, 45, 67, 89, 90, 23, 45, 67, -87};
    int arr2[5] = {1,2,3,4,5};
    int max,min;
    maxmin(arr1, 17, max, min);
    //cout << "Max: " << max << "   "<< "Min: "<< min<<  endl;
    reverse(arr1,17);
    printArray(arr1, 17);
    reverse(arr2,5);
    printArray(arr2, 5);
    return 0;
}