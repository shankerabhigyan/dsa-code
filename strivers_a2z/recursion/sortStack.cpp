//https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void insert(stack<int>&s, int x){
    if(s.empty() || x>s.top()){
        s.push(x);
        return;
    }
    else{
        int t = s.top();
        s.pop();
        insert(s,x);
        s.push(t);
        return;
    }
}

void sortStack(stack<int> &s){
    if(s.empty()) return;
    int x = s.top();
    s.pop();
    sortStack(s);
    insert(s,x);
    return;
}  

void SortedStack :: sort()
{
   sortStack(s);
}

 