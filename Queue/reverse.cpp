#include<bits/stdc++.h>
using namespace std;

queue<int> reverse(queue<int> q){
    queue<int> rev;
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        rev.push(s.top());
        s.pop();
    }
    return rev;
}

int main(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    queue<int> rev = reverse(q);
    while(!rev.empty()){
        cout << rev.front() << " ";
        rev.pop();
    }
    cout << endl;

    return 0;
}