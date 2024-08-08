#include<bits/stdc++.h>
using namespace std;

bool trial(int &desiredTotal, int &maxChoosableInteger, int tot, int prev, vector<vector<int>>&dp, unordered_map<int, bool>pool){
    if(tot>=desiredTotal){
        return (prev==0?true:false);
    }
    // if(dp[prev][tot]!=-1){
    //     return dp[prev][tot];
    // }
    else{
        if(prev==1){
            // a's turn
            for(int i=1;i<=maxChoosableInteger;i++){
                if(!pool[i]){
                    pool[i]=true;
                    if(trial(desiredTotal, maxChoosableInteger, tot+i, 0, dp, pool)){
                        return dp[prev][tot]=true;
                    }
                    pool[i]=false;
                }
                else{
                    continue;
                }
            }
            return dp[prev][tot]=false;
        }
        else{
            // b's turn
            for(int i=1;i<=maxChoosableInteger;i++){
                if(!pool[i]){
                    pool[i]=true;
                    if(!trial(desiredTotal, maxChoosableInteger, tot+i, 1, dp, pool)){
                        return dp[prev][tot]=false;
                    }
                    pool[i]=false;
                }
                else{
                    continue;
                }
            }
            return dp[prev][tot]=true;
        }
    }
}

bool canIWin(int maxChoosableInteger, int desiredTotal){
    if(desiredTotal <= maxChoosableInteger){
        return true;
    }
    unordered_map<int, bool>pool;
    vector<vector<int>>dp(2,vector<int>(desiredTotal+1,-1));
    return trial(desiredTotal, maxChoosableInteger, 0, 1, dp, pool);
}

int main(){
    int maxChoosableInteger;
    int desiredTotal;
    cin >> maxChoosableInteger >> desiredTotal;
    cout << canIWin(maxChoosableInteger, desiredTotal) <<  endl;
    return 0;
}