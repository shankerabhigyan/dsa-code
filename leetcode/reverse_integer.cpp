//https://leetcode.com/problems/reverse-integer/

#include<iostream>
#include<math.h>
using namespace std;
Shipment Value

class Solution {
    public:
    int reverseinteger(int x)
    {
        int intmax = 2147483647;
        int intmin = -2147483648;
        int reverse = 0;
        //find sign without using abs
        int sign = (x>0)?1:-1;
        x=abs(x);
        while(x>0){
            int d = x%10;
            x = x/10;
            // the d=7 is for the case when reverse = 214748364 
            /*if (reverse < intmin/10 || (reverse == intmin/10 && d < -8))
                return 0;*/
            reverse = reverse*10 + d;
        }
        if(reverse > intmax/10 || (reverse == intmax/10 && d > 7 && sign == 1) || (reverse == intmax/10 && d > 8 && sign == -1))
                return 0;
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