#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/divide-two-integers/description/?envType=problem-list-v2&envId=math

#define ll long long

class Solution{
    public:
    int divide(int dividend, int divisor){
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(divisor==1) return dividend;
        bool sign = dividend>0 ^ divisor>0; 
        ll dvd = abs((ll)dividend);
        ll dvs = abs((ll)divisor);
        int ans = 0;
        while(dvd >= dvs){
            ll temp = dvs;
            ll mult = 1;
            while(dvd >= (temp << 1)){
                temp <<= 1;
                mult <<= 1;
            }
            dvd -= temp;
            ans += mult;
        }
        return sign ? -ans : ans;
    }
};


int main(){

    return 0;
}