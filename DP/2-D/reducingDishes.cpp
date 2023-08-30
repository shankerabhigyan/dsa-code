// https://leetcode.com/problems/reducing-dishes/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> satisfaction, int i, int time){
    if(i==satisfaction.size()){
        return 0;
    }

    int include = 
}

int maxSatisfaction(vector<int> satisfaction){

}

int main(){
    vector<int> satisfaction;
    int x;
    cin >> x;
    while(x!=-1){
        satisfaction.push_back(x);
        cin >> x;
    }
    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}