#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/deque_1170059?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio

class Deque{ 
    int* arr;
    int front, rear, size;
    public:
    Deque(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if( (front == 0 && rear == size-1) || (rear == front-1)){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if(front==-1 && rear==-1)
    }

    bool pushFront(int x){
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front = 0;
            rear = 0;
        }
        else if(front==0){
            front = size-1;
        }
        else{
            front --;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        if(isFull()){
            return false;
        }
        else if(rear==-1){
            front = 0;
            rear = 0;
        }
        else if(rear==size-1){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront(){

    }
}

int main(){
    // stl implementation
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_back();
    dq.pop_front();

    cout<<dq.front()<<endl;
    //cout<<dq.back()<<endl;
    cout << dq.empty() << endl;

    return 0;
}