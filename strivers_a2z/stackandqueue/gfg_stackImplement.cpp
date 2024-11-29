#include<bits/stdc++.h>
using namespace std;

class MyStack{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack::push(int x){
    MyStack::top = MyStack::top+1;
    arr[MyStack::top] = x; 
}

int MyStack::pop(){
    if(MyStack::top==-1) return -1;
    int x = MyStack::arr[MyStack::top];
    MyStack::top = MyStack::top-1;
    return x;
}

int main(){

    return 0;
}