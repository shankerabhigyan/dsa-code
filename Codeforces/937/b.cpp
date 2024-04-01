// https://codeforces.com/contest/1950/problem/B
#include<bits/stdc++.h>
using namespace std;

void swap(char &ch){
    if(ch=='#'){
        ch = '.';
    }
    else{
        ch = '#';
    }
}

void printCheckboard(int n){
    int t = 2;
    vector<vector<char>> checkboard(2*n, vector<char>(2*n, '0'));
    char ch = '#';
    for(int i=0; i<2*n; i+=2){
        if(i==0){
            i=0;
        }
        else if(n%2==0){
            swap(ch);
        }
        for(int j=0; j<2*n; j++){
            if(t>0){
                checkboard[i][j] = ch;
                checkboard[i+1][j] = ch;
                t--;
            }
            else{
                swap(ch);
                t = 2;
                checkboard[i][j] = ch;
                checkboard[i+1][j] = ch;
                t--;
            }
        }
    }
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            cout << checkboard[i][j];
        }
        cout << endl;
    }
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n;
        cin >> n;
        printCheckboard(n);
    }
    return 0;
}