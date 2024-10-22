#include<bits/stdc++.h>
using namespace std;

long countSalutes(string A){
    long countIncoming = 0;
    long ans = 0;
    for(char ch:A){
        if(ch=='>') countIncoming++;
        else ans+=countIncoming;
    }
    return ans;
}

int main(){
    string a;
    cin >> a;
    cout << countSalutes(a) << endl;
    return 0;
}