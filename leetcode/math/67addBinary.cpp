#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int toint(char ch){
        return ch-'0';
    }
    string addBinary(string a, string b) {
        string ans = "";
        int sum = stoi(a) + stoi(b);
        string ans = to_string(sum);
        bool carry = false;
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]=='2'){
                if(carry){
                    ans[i]='1';
                }
                else{
                    ans[i]='0';
                    carry=true;
                }
            }
            else if(ans[i]=='1'){
                if(carry){
                    ans[i]='0';
                }
                else{
                    ans[i]='1';
                }
            }
            else{
                if(carry){
                    ans[i]='1';
                    carry = false;
                }
            }
        }
        if(carry){
            ans = "1"+ans;
        }
        return ans;
    }
};