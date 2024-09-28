#include<bits/stdc++.h>
using namespace std;

int permute(string A, string B){
    if(A.length()!=B.length()) return 0;
    unordered_map<char,int> track;
    for(char ch:A){
        track[ch]++;
    }
    for(char ch:B){
        if(track[ch]){
            track[ch]--;
        } 
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    string A, B;
    cin >> A >> B;
    cout << permute(A,B) << endl;
    return 0;
}