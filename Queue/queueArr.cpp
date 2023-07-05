#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int qfront, rear, size;
    int* arr;
    
    Queue(){
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty(){ // O(1)
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){ // O(1)
        if(rear==size){
            cout << "Queue is packed!";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){ // O(1)
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront]; 
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front(){
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};


int main(){

    return 0;
}