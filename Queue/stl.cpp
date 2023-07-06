#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    cout<<q.front() << endl;
    q.push(2);
    cout<<q.front() << endl;
    q.push(3);
    cout<<q.front() << endl;
    //q.pop();
    q.front() = 5;
    cout<<q.front()<< endl;
    //q.back() = 5;
    q.swap(q);
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    cout << q.front() << endl;
}