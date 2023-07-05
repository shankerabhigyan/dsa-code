// sorting a stack without using loops
// stack can have duplicates
// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio
// smallest element should be at the bottom of the stack

#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop(); 
    }
    cout << endl;
}

void SortPass(stack<int> &s){
    int x = s.top();
    s.pop();
    int y = s.top();
    s.pop();
    if(x<y){
        s.push(x);
        if(s.size()>=2){
            SortPass(s);
            s.push(y);
            return;
        }
        else{
            s.push(y);
            return;
        }
    }
    else if(y<=x){
        s.push(y);
        if(s.size()>=2){
            SortPass(s);
            s.push(x);
            return;
        }
        else{
            s.push(x);
            return;
        }
    }
}

void Sort(stack<int> &s){
    if(s.empty() || s.size()==1){
        return;
    }
    int el = s.top();
    s.pop();
    Sort(s);
    s.push(el);
    SortPass(s);
    return;
}

int main(){
    stack <int> s;
    int n;
    cin >> n;
    while(n-->0){
        int x;
        cin >> x;
        s.push(x);
    }
    Sort(s);
    print(s);

    return 0;
}