#include<bits/stdc++.h>
using namespace std;

string bullsandcows(string A, string B){
    int bulls=0, cows=0;
    unordered_map<char,int> count;
    for(int i=0;i<A.length();i++){
        if(A[i]==B[i]){
            bulls++;
            B[i] = 'x';
        }
        else{
            count[A[i]]?count[A[i]]++:count[A[i]]=1;
        }
    }
    for(char ch:B){
        if(count[ch]>0){
            cows++;
            count[ch]--;
        }
    }
    return to_string(bulls)+"A"+to_string(cows)+"B";
}

int main(){
    string A, B;
    cin >> A >> B;
    cout << bullsandcows(A,B) << endl;
    return 0;
}