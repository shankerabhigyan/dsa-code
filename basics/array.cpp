#include<iostream>
#include<math.h>
using namespace std;

void printArray(int array[], int size){
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    
    int arr[17] = {0};
    fill_n(arr, 17, 5);
    //cout << sizeof(arr)/sizeof(int) << endl;
    //cout << arr[6] << endl;
    printArray(arr, sizeof(arr)/sizeof(int));
    return 0;
}