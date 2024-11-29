#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
stack<int> st1;
stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            int x = st1.top();
            st2.push(x);
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty()){
            int x = st2.top();
            st1.push(x);
            st2.pop();
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;   
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */