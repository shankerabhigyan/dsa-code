#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int ans = 1;
        for(int i=2;i<=n;i++){
            ans = a+b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

int main(){
    return 0;
}