// https://www.codingninjas.com/studio/problems/circular-queue_1170058?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio
#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
    int front,rear,size;
    int *arr;

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        for(int i=0;i<size;i++){
            arr[i] = -1;    
        }
        front = 0;
        rear = 0;
    }

    bool enqueue(int value){
        if(rear == front && arr[front]!=-1){
            return false;
        }
        else{   
            arr[rear] = value;
            if(rear==size-1){
                rear = 0; 
            }
            else{
                rear++;
            }
            return true;
        }
    }

    int dequeue(){
        if(rear == front && arr[front] == -1){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            if(front==size-1){
                front=0;
            }
            else{
                front++;
            }
            return ans;
        }
    }
};

int main(){

    return 0;
}