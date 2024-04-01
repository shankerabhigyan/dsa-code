// https://codeforces.com/contest/1950/problem/C
#include<bits/stdc++.h>
using namespace std;

string get12HourFormat(string &time){
    int h = stoi(time.substr(0, 2));
    string m = time.substr(3, 2);
    if(h<13 && h>0){
        if(h<12){
            return time + " AM";
        }
        else{
            return time + " PM";
        }
    }
    else if (h>=13 && h<=23){
        int h1 = h - 12;
        if(h1<10){
            return "0" + to_string(h1) + ":" + m + " PM";
        }
        return to_string(h1) + ":" + m + " PM";
    }
    else{
        return "12:" + m + " AM";
    }
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        string time;
        cin >> time;
        string t = get12HourFormat(time);
        cout << t << endl;
    }
    return 0; 
}