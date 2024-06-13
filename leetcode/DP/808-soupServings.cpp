#include<bits/stdc++.h>
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

pair<int,int> op1(int a, int b){
    return {max(a-100,0),b};
}

pair<int,int> op2(int a, int b){
    return {max(a-75,0),max(b-25,0)};
}

pair<int,int> op3(int a, int b){
    return {max(a-50,0),max(b-50,0)};
}

pair<int,int> op4(int a, int b){
    return {max(a-25,0),max(b-75,0)};
}

double recurse(int a, int b, unordered_map<pair<int,int>,double,hash_pair> &dp){
    if(a==0 && b==0){
        return 0.5;
    }
    if(a==0){
        return 1;
    }
    if(b==0){
        return 0;
    }
    if(dp.find({a,b})!=dp.end()){
        return dp[{a,b}];
    }
    else{
        vector<pair<int,int>> list;
        list.push_back(op1(a,b));
        list.push_back(op2(a,b));
        list.push_back(op3(a,b));
        list.push_back(op4(a,b));
        double ans = 0;
        for(auto x:list){
            ans = ans + 0.25 * recurse(x.first,x.second,dp);
        }
        return dp[{a,b}] = ans;
    }
}

double brew(int n){
    unordered_map<pair<int,int>,double,hash_pair> dp;
    double ans = recurse(n,n,dp);
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << brew(n) << endl;
    return 0;
}