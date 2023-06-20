#include<bits/stdc++.h>
using namespace std;


void powerSet(vector<int> v, int index, vector<int> output, vector<vector<int>> &ans){
    int n = v.size();
    if(index==n){
        ans.push_back(output);
        return;
    }

    //include
    output.push_back(v[index]);
    powerSet(v,index+1,output,ans);

    //exlude
    output.pop_back();
    powerSet(v,index+1,output,ans);

    return;
    
}

int main(){
    vector<int> v;
    int n,x;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter elements of array : ";
    while(n-- > 0){
        cin >> x;
        v.push_back(x);
    }

    vector<int> output;
    vector<vector<int>> ans;
    powerSet(v,0,output,ans);
    int count = 0;

    cout << "Power set : " << endl;

    for(auto i : ans){
        cout << "[ ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << "], ";
        count++;
    }
    cout << endl;
    cout << "Total number of subsets : " << count << endl;

    return 0;
}