#include<bits/stdc++.h>
using namespace std;

void backtrack(string &A, int i, string curr, unordered_map<char,vector<char>> &map, vector<string>&ans){
    if(i==A.size()){
        ans.push_back(curr);
        return;
    }
    else{
        for(char ch:map[A[i]]){
            backtrack(A,i+1,curr+ch,map,ans);
        }
        return;
    }
}

vector<string> letterCombinations(string A){
    unordered_map<char,vector<char>> map;
    map['0'] = {'0'};
    map['1'] = {'1'};
    map['2'] = {'a','b','c'};
    map['3'] = {'d','e','f'};
    map['4'] = {'g','h','i'};
    map['5'] = {'j','k','l'};
    map['6'] = {'m','n','o'};
    map['7'] = {'p','q','r','s'};
    map['8'] = {'t','u','v'};
    map['9'] = {'w','x','y','z'};
    vector<string> ans;
    backtrack(A,0,"",map,ans);
    return ans;
}

int main(){
    string A;
    cin >> A;
    vector<string> lc = letterCombinations(A);
    for(auto s:lc){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}