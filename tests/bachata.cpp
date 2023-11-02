#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string>> matchmaking(vector<pair<string,int>> &v){
    // max difference of 2 inches
    // first come first serve
    // shorter height priority
    vector<pair<string,string>> ans;
    sort(v.begin(),v.end(),[](pair<string,int> a, pair<string,int> b){
        return a.second<b.second;
    });

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(abs(v[i].second-v[j].second)<=2){
                ans.push_back({v[i].first,v[j].first});
                v.erase(v.begin()+j);
                break;
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<pair<string,int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    vector<pair<string,string>> ans = matchmaking(v);
    cout << endl << "Matchmaking: " << endl;
    for(auto x:ans){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}