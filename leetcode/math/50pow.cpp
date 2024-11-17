#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1.0) return 1.0;

        if(n>0){
            double ans = x;
            long long pow = 1;
            while(pow*2<=n){
                ans = ans*ans;
                pow = pow*2;
            }
            while(pow<n){
                ans *= x;
                pow++;
            }
            return ans;
        }
        else{
            double ans = 1/x;
            long long pow=-1;
            while(pow*2>=n){
                ans = ans*ans;
                pow = pow*2;
            }
            while(pow>n){
                ans /= x;
                pow--;
            }
            return ans;
        }
    }
};

// OPTIMIZED
class Solution2 {
public:
    double myPow(double x, int n) {
        // Handle base cases
        if (n == 0) return 1.0;
        if (x == 1.0) return 1.0;
        if (x == -1.0) return (n % 2 == 0) ? 1.0 : -1.0;
        
        // Convert n to long long to handle INT_MIN case
        long long power = n;
        if (power < 0) {
            x = 1/x;
            power = -power;
        }
        
        double result = 1.0;
        while (power > 0) {
            // If power is odd, multiply result by x
            if (power & 1) {
                result *= x;
            }
            // Square x and half the power
            x *= x;
            power >>= 1;
        }
        
        return result;
    }
};