#include<bits/stdc++.h>
using namespace std;

// recursive approach
void generateParenthesis(stack<int> s, string str, vector<string>&ans, int open, int close){
    if(open==0 && close==0){
        ans.push_back(str);
        return;
    }
    if(open==0){
        while(close--){
            str.push_back(')');
            s.pop();
        }
        ans.push_back(str);
        return;
    }
    if(s.size()==0 || open==close){
        str.push_back('(');
        open--;
        s.push(1);
        generateParenthesis(s,str,ans,open,close);
        return;
    }
    else{
        // either open or close can be added

        // case 1: open
        str.push_back('(');
        open--;
        s.push(1);
        generateParenthesis(s,str,ans,open,close);

        // case 2: close
        str.pop_back();
        open++;
        str.push_back(')');
        close--;
        s.pop();
        generateParenthesis(s,str,ans,open,close);
        return;
    }
} 



vector<string> generateParenthesis(int n){
    vector<vector<string>> dp(n + 1);
    dp[0].push_back("");  // Base case: A single empty string for 0 pairs.

    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < k; ++i) {
            for (string left : dp[i]) {
                for (string right : dp[k - i - 1]) {
                    dp[k].push_back("(" + left + ")" + right);
                }
            }
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for(auto x: ans){
        cout << x << endl;
    }
    return 0;
}