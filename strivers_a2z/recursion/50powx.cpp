#include<bits/stdc++.h>
using namespace std;

/*
double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;
        if(power<0){
            x = 1/x;
            power = -power;
        }
        while(power>0){
            if(power&1){
                ans*=x;
            }
            x*=x;
            power >>=1;
        }
        return ans;
    }
*/

class Solution {
public:
    double recurse(long long power, double ans, double&x){
        if(power==0) return 1;
        if(power==1) return ans*x;
        if(power&1) ans*=x;
        x*=x;
        return recurse(power/2, ans, x);
    }
    double myPow(double x, int n) {
        long long power = n;
        if(n<0){
            x = 1/x;
            power = -power;
        }
        return recurse(power, 1.0, x);
    }
};