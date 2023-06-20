#include<bits/stdc++.h>
using namespace std; 

void keypad(int x, vector<vector<string>> &ans, vector<string> v, vector<string> output){
    if(x==0){
        ans.push_back(output);
        return;
    }
    for(int i=0; i<v[x%10].size(); i++){
        string str = v[x%10];
        output.push_back(str.substr(i,1));
        //output.push_back();
        keypad(x/10,ans,v,output);
        output.pop_back();
    }
    return;
    
}

int main(){
    int x; 
    cout << "Enter your digits : ";
    cin >> x;
    vector<string> v;
    v.push_back(""); // 0
    v.push_back(""); // 1
    v.push_back("abc"); // 2
    v.push_back("def"); // 3
    v.push_back("ghi"); // 4
    v.push_back("jkl"); // 5
    v.push_back("mno"); // 6
    v.push_back("pqrs"); // 7
    v.push_back("tuv"); // 8
    v.push_back("wxyz"); // 9

    // reverse digits
    int temp = x;
    int rev = 0;
    while(temp>0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }

    vector<vector<string>> ans;
    vector <string> output;
    keypad(rev,ans,v,output);
    cout << "All possible combinations : " << endl;
    for(auto i : ans){
        cout << "[ ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}