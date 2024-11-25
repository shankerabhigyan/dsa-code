#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/count-good-numbers/

# define MOD 1000000007

class Solution {
public:
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        
        return (power(5, evenPos) * power(4, oddPos)) % MOD;
    }
};

int main() {
    Solution sol;
    long long n;
    cin >> n;
    cout << sol.countGoodNumbers(n) << endl;
    return 0;
}