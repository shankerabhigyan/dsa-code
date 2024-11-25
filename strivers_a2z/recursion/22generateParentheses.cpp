// https://leetcode.com/problems/generate-parentheses/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void addBraces(int bal, int n, string s, vector<string> &ans){
        if(bal==0 && n==0){
            ans.push_back(s);
            return;
        }
        if(n==0){
            while(bal>0){
                s += ")";
                bal--;
            }
            addBraces(bal,n,s,ans);
        }
        else{
            addBraces(bal+1,n-1,s+"(",ans);
            if(bal>0){
                addBraces(bal-1,n,s+")",ans);
            }
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        int bal = 0;
        vector<string> ans;
        addBraces(0,n,"",ans);
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution* sol = new Solution();
    vector<string> ans = sol->generateParenthesis(n);
    for(string s:ans){
        cout << s << endl;
    }
    return 0;
}