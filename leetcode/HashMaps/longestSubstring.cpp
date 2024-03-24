#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string ss){
    unordered_map<int, int> mp;
    int start = 0, end = 0, n = ss.size(), ans = 0;
    while(end<n){
        if(mp.find(ss[end])!=mp.end()){
            ans = max(ans, end-start);
            start = max(start, mp[ss[end]]+1);
        }
        mp[ss[end]] = end;
        end++;
    }
    ans = max(ans, end-start);
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longestSubstring(s) << endl;
    return 0;
}