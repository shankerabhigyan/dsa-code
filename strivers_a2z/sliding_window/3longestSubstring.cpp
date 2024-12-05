#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,max_length=INT_MIN;
        unordered_map<char,int> hash;
        while(r<s.length()){
            char ch = s[r];
            if(!hash[ch] || hash[ch]-1<l){
                max_length = max(max_length,r-l+1);
                hash[ch]=r+1;
                r++;
            }
            else{
                l = hash[ch];
            }
        }
        return max_length;
    }
};

int main(){
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}