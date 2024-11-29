// https://www.geeksforgeeks.org/problems/better-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=better-string

#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     string betterString(string str1, string str2) {
//         int n = str1.length();
//         int len = 1<<n;
//         unordered_set<string> set1;
//         unordered_set<string> set2;
//         vector<int> count(2,0);
//         for(int mask=0;mask<len;mask++){
//             string a1 = "", a2 = "";
//             for(int i=0;i<n;i++){
//                 if(mask & (1<<i)){
//                     a1 += str1[i];
//                     a2 += str2[i];
//                 }
//             }
//             set1.insert(a1);
//             set2.insert(a2)
//         }
//         return set1.size() >= set2.size() ? str1 : str2;
//     }
// };

class Solution{
public:
    int countSubsequences(string &str){
        int n = str.length();
        vector<int> last (256,-1);
        // ^^ ascii
        vector<int> dp(n+1); // int coz n<=30 so 2^30 within range
        dp[0]=1;

        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1]*2;
            if(last[str[i-1]]!=-1){
                dp[i] -= dp[last[str[i-1]]];
            //  ^^ subtract the number of subsequences that were possible right before the previous occurrence
            }

            last[str[i-1]] = i-1;
        }
        return dp[n];
    }

    string betterString(string str1, string str2){
        return countSubsequences(str1)>=countSubsequences(str2)? str1:str2;
    }
};

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    Solution sol;
    string result = sol.betterString(str1, str2);
    cout << "The better string is: " << result << endl;

    return 0;
}