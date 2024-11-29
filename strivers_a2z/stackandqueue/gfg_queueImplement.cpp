#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

void MyQueue::push(int x){
    MyQueue::arr[MyQueue::rear] = x;
    MyQueue::rear++;
}
int MyQueue::pop(){
    if(MyQueue::rear==MyQueue::front) return -1;
    else{
        int x = MyQueue::arr[MyQueue::front];
        MyQueue::front++;
        return x;
    }
}