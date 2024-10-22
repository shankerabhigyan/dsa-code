#include<bits/stdc++.h>
using namespace std;

string intToRoman(int A){
    string ans;
    unordered_map<int, string> m;
    m[1] = "I";
    m[5] = "V";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
    m[4] = "IV";
    m[9] = "IX";
    m[40] = "XL";
    m[90] = "XC";
    m[400] = "CD";
    m[900] = "CM";

    int div = 1000;
    while(A){
        int q = A/div;
        if(q){
            if(q == 9 || q == 4){
                ans += m[q*div];
            }
            else if(q >= 5){
                ans += m[5*div];
                q -= 5;
                while(q--){
                    ans += m[div];
                }
            }
            else{
                while(q--){
                    ans += m[div];
                }
            }
        }
        A %= div;
        div /= 10;
    }
    return ans;
}

int main(){
    int A;
    cin >> A;
    cout << intToRoman(A) << endl;
    return 0;
}