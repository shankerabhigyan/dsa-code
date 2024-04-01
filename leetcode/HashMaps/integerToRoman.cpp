// https://leetcode.com/problems/integer-to-roman/description/
#include<bits/stdc++.h>
using namespace std;

string intToRoman(int n){
    unordered_map<int, string> mp;
    mp[1] = "I";
    mp[5] = "V";
    mp[10] = "X";
    mp[50] = "L";
    mp[100] = "C";
    mp[500] = "D";
    mp[1000] = "M";
    mp[4] = "IV";
    mp[9] = "IX";
    mp[40] = "XL";
    mp[90] = "XC";
    mp[400] = "CD";
    mp[900] = "CM";

    string ans = "";

    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    int power = 1;
    while (n>0){
        string temp = "";
        int x = n%10 * power;
        n = n/10;
        power *= 10;

        if(x == 0){
            continue;
        }
        
        else{
            while(x>0){
                if(mp.find(x)!=mp.end()){
                    temp += mp[x];
                    x = 0;
                }
                else if(x<5){
                    temp += mp[1];
                    x--;
                }
                else if(x<10){
                    temp += mp[5];
                    x-=5;
                }
                else if(x<50){
                    temp += mp[10];
                    x -= 10;
                }
                else if(x<100){
                    temp += mp[50];
                    x -= 50;
                }
                else if(x<500){
                    temp += mp[100];
                    x -= 100;
                }
                else if(x<1000){
                    temp += mp[500];
                    x -= 500;
                }
                else{
                    temp += mp[1000];
                    x -= 1000;
                }
            }
        }
        ans = temp + ans;
    }
    return ans;
}

string intToRomanOpt(int n){
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = "";
    for(int i=0; i<values.size(); i++){
        while(n>=values[i]){
            n -= values[i];
            ans += symbols[i];
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << intToRomanOpt(n) << endl;
    return 0;
}