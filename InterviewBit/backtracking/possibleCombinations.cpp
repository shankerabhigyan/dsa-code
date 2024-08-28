// https://www.interviewbit.com/problems/all-possible-combinations/
#include<bits/stdc++.h>
using namespace std;

vector<string> backtrack(vector<string>&V, int idx){
    if(idx==V.size()-1){
        string s = V[idx];
        sort(s.begin(),s.end());
        vector<string> v = {};
        for(char x:s){
            v.push_back(string(1,x));
        }
        return v;
    }
    else{
        vector<string> v = backtrack(V, idx+1);
        vector<string> v2 = {};
        string s = V[idx];
        sort(s.begin(),s.end());
        for(char x:s){
            for(string ss:v){
                v2.push_back(string(1,x)+ss);
            }
        }
        return v2;
    }
}

vector<string> specialStrings(vector<string> &V){
    return backtrack(V, 0);
}

int main(){
    int n;
    cin >> n;
    vector<string> V(n);
    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    vector<string> ans = specialStrings(V);
    for(auto s:ans){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}