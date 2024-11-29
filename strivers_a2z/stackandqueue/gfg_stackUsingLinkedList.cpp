#include<bits/stdc++.h>
using namespace std;


struct StackNode{
    int data;
    StackNode* next;

    StackNode(int a){
        data = a;
        next = NULL;
    }
};

class MyStack{
private:
    StackNode* top;
public:
    void push(int x){
        if(top==NULL){
            top = new StackNode(x);
        }
        else{
            StackNode* temp = new StackNode(x);
            temp->next = top;
            top = temp;
        }
    }

    int pop(){
        if(top==NULL) return -1;
        else{
            int x = top->data;
            top = top->next;
            return x;
        }
    }

    MyStack(){
        top=NULL;
    }
};

int main(){

    return 0;
}