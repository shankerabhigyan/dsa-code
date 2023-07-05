// https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio
#include<bits/stdc++.h>
using namespace std;

void print(stack<char> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop(); 
    }
    cout << endl;
}


int findMinimumCost(string str){
    if(str.length()%2!=0){
        return -1;
    }
    stack <char> s;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        s.push(ch);
    }
    s = simplify(s);
    print(s);
    return 0;
}

int main(){
    string s;
    cin >> s;
    int i = findMinimumCost(s);
    cout << i << endl;
    return 0;
}