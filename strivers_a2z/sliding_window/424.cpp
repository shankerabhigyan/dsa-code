// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0;
        int n = s.length();
        map<int,int> mp;
        int f = 0;
        while(r<n){
            mp[s[r]]++;
            f = max(f,mp[s[r]]);
            int x = r-l+1-f;
            if(x>k){
                if(--mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            else{
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}