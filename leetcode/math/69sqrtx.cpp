#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        long long int temp = x/2;
        while(temp/2 *temp/2 > x){
            temp = temp/2;
        }
        while(temp*temp>x){
            temp--;
        }
        return temp;
    }
};

int main() {
    int x;
    cin >> x;
    
    Solution sol;
    int result = sol.mySqrt(x);
    
    cout <<  result << endl;
    
    return 0;
}