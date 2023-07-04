#include<bits/stdc++.h>
using namespace std;

int main(){
    stack <int> s;
    int x;
    cin >> x;
    while(x!=-1){
        s.push(x);
        cin >> x;
    }
    int mid = s.size()/2;
    stack <int> temp;
    while(mid>0){
        temp.push(s.top());
        s.pop();
        mid--;
    }
    s.pop();
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }

    // printing the stack
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}