#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans(n1,-1);

        for(int i=0;i<n1;i++){
            mp[nums1[i]]=i+1;
        }
        
        for(int j=n2-1;j>=0;j--){
            int x = nums2[j];
            while(!st.empty()){
                if(x>=st.top()) st.pop();
                else break;
            }
            if(!st.empty() && mp[x])ans[mp[x]-1]=st.top();
            st.push(x);
        }
        return ans;
    }
};

int main(){

    return 0;
}