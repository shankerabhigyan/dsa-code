// remove first k elements from the queue
// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
#include<bits/stdc++.h>
using namespace std;

queue<int> reverseK(queue<int>q, int k){
    stack<int> s;
    while(k>0){
        s.push(q.front());
        q.pop();
        k--;
    }
    queue<int> rev;
    while(!s.empty()){
        rev.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        rev.push(q.front());
        q.pop();
    }
    return rev;
}


int main(){
    queue<int> q;
    int n, k;
    cin >> n >> k;

    while(n--){
        int x;
        cin >> x;
        q.push(x);
    }

    queue<int> rev = reverseK(q, k);
    while(!rev.empty()){
        cout << rev.front() << " ";
        rev.pop();
    }
    cout << endl;

    return 0;
}