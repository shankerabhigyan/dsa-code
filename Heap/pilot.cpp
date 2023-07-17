#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int maxSize;
    int heapSize;

    MaxHeap(int maxSize){
        heapSize = 0;
        maxSize = maxSize;
        arr = new int[maxSize];
    } // constructor

    int getParent(int i){
        return (i-1)/2;
    }

    void insert(int val){ // O(log(n)) --worst case
        if(heapSize == maxSize){
            cout << "heap overflow for int "<< val << "." << endl;
        }
        heapSize = heapSize + 1;
        int i = heapSize-1;
        arr[i] = val;

        // check heapify property
        while(i>0 && arr[getParent(i)]<arr[i]){
            swap(arr[getParent(i)],arr[i]);
            i = getParent(i);
        }
    }

    void MaxHeapify(int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
    }

    void removeMax(){

    }

    void deletekey(int i){

    }

    void display(){
        for(int i=0; i<heapSize; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    MaxHeap heap(10);
    heap.insert(1);
    heap.insert(2);
    heap.insert(5);
    heap.insert(3);
    heap.insert(4);
    heap.insert(10);
    heap.display();

    return 0;
}