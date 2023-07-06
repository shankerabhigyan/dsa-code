// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// first non repeating character in a stream
// input is only lowercase letters

#include<bits/stdc++.h>
using namespace std;

string firstNonRepeatingChar(string a){
    map<char, int> m;
    string ans = "";
    queue<char> q;
    for(int i=0;i<a.length();i++){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = 1;
            q.push(a[i]);
        }
        else{
            m[a[i]]++;
        }

        while(!q.empty()){
            if(m[q.front()] == 1){
                ans += q.front();
                break;
            }
            else{
                q.pop();
            }
        }
        if(q.empty()){
            ans += '#';
        }
    }
    return ans;
}


int main(){
    string s;
    cin >> s;

    cout << firstNonRepeatingChar(s) << endl;

    return 0;
}