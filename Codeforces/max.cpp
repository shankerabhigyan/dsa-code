#include<bits/stdc++.h>
using namespace std;
/*
There are 2n
 positive integers written on a whiteboard. Being bored, you decided to play a one-player game with the numbers on the whiteboard.

You start with a score of 0
. You will increase your score by performing the following move exactly n
 times:

Choose two integers x
 and y
 that are written on the whiteboard.
Add min(x,y)
 to your score.
Erase x
 and y
 from the whiteboard.
Note that after performing the move n
 times, there will be no more integers written on the whiteboard.

Find the maximum final score you can achieve if you optimally perform the n
 moves.
*/

int maxSum(vector<int>a, int n){
    // find sum of even indexed elements
    int sum=0;
    for(int i=0;i<2*n;i+=2){
        sum+=min(a[i],a[i+1]);
    }
    return sum;
}

int main(){
    int n, testcases;
    cin >> testcases;
    while(testcases--){
        cin>>n;
        vector<int> a(2*n);
        for(int i=0;i<2*n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        cout<<maxSum(a,n)<<endl;
    }
    return 0;
}