#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int top;
    int *arr;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x){
        if(size-top>1){
            top++;
            arr[top] = x;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<< "Stack Underflow" << endl;
        }
    }

    int peek(){
        if(top>=0){
            //cout<<endl;
            return arr[top];
        }
        else{
            //cout<<"Empty Stack";
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    /*stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;*/

    Stack st(5);
    cout << st.peek() <<endl;
    st.push(11);
    st.push(92);
    st.push(47);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    
    return 0;
}