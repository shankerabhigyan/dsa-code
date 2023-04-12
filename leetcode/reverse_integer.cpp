//https://leetcode.com/problems/reverse-integer/

#include<iostream>
#include<math.h>
using namespace std;

class Solution {
    public:
    int reverseinteger(int x)
    {
        if(x == 0)
            return 0;
        int intmax = 2147483647;
        int intmin = -2147483648;
        int reverse = 0;
        int sign = x/abs(x);
        x=abs(x);
        while(x>0){
            int d = x%10;
            x = x/10;
            if(reverse > intmax/10 || (reverse == intmax/10 && d > 7))
                return 0;
            if (reverse < intmin/10 || (reverse == intmin/10 && d < -8))
                return 0;
            reverse = reverse*10 + d;
        }
        return reverse*sign;
    }
};

int main()
{
    Solution s;
    int x = 0;
    cin >> x;
    cout << s.reverseinteger(x) << endl;
    return 0;
}