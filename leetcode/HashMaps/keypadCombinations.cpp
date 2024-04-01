#include<bits/stdc++.h>
using namespace std;

void solve(unordered_map<char,string> &phoneMap, string &digits, vector<string> &combinations, int i, string combination){
    if(i==digits.size()){
        combinations.push_back(combination);
        return;
    }
    for(char c: phoneMap[digits[i]]){
        solve(phoneMap, digits, combinations, i+1, combination+c);
    }
}

vector<string> letterCombinations(string digits){
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    if (digits.size() == 0){
        return {};
    }
    vector<string> combinations;
    solve(phoneMap, digits, combinations, 0 , "");
    return combinations;
}

int main(){
    string digits;
    cin>>digits;
    vector<string> combinations = letterCombinations(digits);
    for(string s: combinations){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}