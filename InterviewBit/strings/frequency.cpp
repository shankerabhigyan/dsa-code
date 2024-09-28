#include<bits/stdc++.h>
using namespace std;

string freq(string &s){
    unordered_map<char,int>map;
    vector<char> order;
    for(char ch:s){
        if(map[ch]){
            map[ch]++;
        }
        else{
            map[ch]=1;
            order.push_back(ch);
        }
    }
    string ans;
    for(char ch:order){
        ans+= ch+to_string(map[ch]);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << freq(s) << endl;
    return 0;
}