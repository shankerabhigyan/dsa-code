#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans = digits;
        bool carry = false;
        for(int i=ans.size()-1;i>=0;i--){
            if((ans[i]+1)/10==0){
                ans[i]++;
                return ans;
            }
            else{
                ans[i]=0;
            }
        }
        ans.insert(ans.begin(),1);
        return ans;
    }
};

