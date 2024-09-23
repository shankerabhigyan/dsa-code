#include<bits/stdc++.h>
using namespace std;

string solve(string A, int B){
    if(A.length()==1) return B==1?"":A;
    int i = 0;
    while(i<A.length()){
        char ch = A[i];
        int start = i;
        int end = i;
        while(end<A.length() && ch==A[end]){
            end++;
        }
        int length = end-start;
        if(length==B){
            A.erase(start,length);
            i = start;
        }
        else{
            i = end;
        }
    }
    return A;
}

int main(){
    string s;
    cin >> s;
    int B;
    cin >> B;
    cout << solve(s,B) << endl;
}