#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(empty()){
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        if(q1.size()>0) return 0;
        return 1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */