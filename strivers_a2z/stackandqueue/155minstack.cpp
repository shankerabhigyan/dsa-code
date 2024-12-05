#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<pair<int,int>> st1;
    int min = INT_MAX;
public:
    MinStack() {
        // empty
    }

    void push(int val) {
        if(val<min){
            min = val;
        }
        st1.push({val,min});
    }
    
    void pop() {
        st1.pop();
        if(st1.empty()){
            min = INT_MAX;
        }
        else{
            min = st1.top().first;
        }
    }
    
    int top() {
        return st1.top().first;
    }
    
    int getMin() {
        return st1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

    return 0;
}