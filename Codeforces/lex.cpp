#include<bits/stdc++.h>
using namespace std;

void display(vector<int>res){
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

vector<int> findLexicographicallyLargest(vector<int>arr, set<int>st){
    if(arr.size()==0){
        vector<int>b(st.begin(),st.end());
        reverse(b.begin(),b.end());
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    display(findLexicographicallyLargest(arr));
    return 0;
}