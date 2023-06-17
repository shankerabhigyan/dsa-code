#include<bits/stdc++.h>
using namespace std;
// todo : solve using DP
int stairWays(int n)
{
    if(n==2||n==1){
        return n;
    }
    return stairWays(n-1) + stairWays(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << stairWays(n) << endl;

}