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
        int i = heapSize++;
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

        if(l<heapSize && arr[l]>arr[i]){
            largest = l;
        }
        if(r<heapSize && arr[r]>arr[largest]){
            largest = r;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            MaxHeapify(largest);
        }
    }

    int removeMax(){
        if(heapSize<=0){
            return INT_MIN;
        }
        if(heapSize==1){
            heapSize--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heapSize-1];
        heapSize--;
        MaxHeapify(0);
        return root;
    }

    void increaseKey(int i, int val){
        arr[i] = val;
        while(i>0 && arr[getParent(i)]<arr[i]){
            swap(arr[getParent(i)],arr[i]);
            i = getParent(i);
        }
    }

    void deletekey(int i){
        increaseKey(i, INT_MAX);
        removeMax();
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
    int x;
    cout << "Enter elements of the heap, (terminates @ -1)" << endl; 
    cin >> x;
    while(x!=-1){
        heap.insert(x);
        cin >> x;
    }
    cout << "initial heap..." << endl;
    heap.display();
    
    cout << endl << "enter index to be deleted : ";
    cin >> x;
    heap.deletekey(x);
    cout << "new heap..." << endl;
    heap.display();

    return 0;
}