#include<bits/stdc++.h>
using namespace std;

string solve(int A){
    if(A==0 || A==1){
        return "1";
    }
    vector<int> digits(1,1);

    auto multiply = [](vector<int>&digits, int x){
        int carry = 0;
        for(int &d : digits){
            int product = d*x  + carry;
            d = product%10;
            carry = product/10;
        }
        while(carry>0){
            digits.push_back(carry%10);
            carry = carry/10;
        }
    };

    for(int i=2;i<=A;i++){
        multiply(digits,i);
    }
    string result;
    reverse(digits.begin(),digits.end());
    for(int digit:digits){
        result+=to_string(digit);
    }
    return result;
}

int main(){

    return 0;
}