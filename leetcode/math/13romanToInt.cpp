#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/roman-to-integer/description/?envType=problem-list-v2&envId=math

class Solution{
    public:
    int romanToInt(string s){
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0;
        for(int i=0;i<s.length()-1;i++){
            if(mp[s[i]]<mp[s[i+1]]){
                ans-=mp[s[i]];
            }
            else{
                ans+=mp[s[i]];
            }
        }
        ans+=mp[s[s.length()-1]];
        return ans;
    }
};

int main() {
    Solution sol;
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    int result = sol.romanToInt(roman);
    cout << "The integer value is: " << result << endl;
    return 0;
}