// https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=generate-binary-strings-without-consecutive-1s

#include<bits/stdc++.h>
using namespace std;

void addBit(int i, int &max, string s, bool prev, vector<string>&ans){
    if(i>max) {
        ans.push_back(s);
        return;
    }
    if(prev){
        addBit(i+1, max, s+"0", false, ans);
    }
    else{
        addBit(i+1, max, s+"0", false, ans);
        addBit(i+1, max, s+"1", true, ans);
    } 
    return;
}

vector<string> generateBinaryString(int n){
    vector<string> ans;
    addBit(1,n,"",false,ans);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string>vec = generateBinaryString(n);
    for(string s:vec){
        cout << s << endl;
    }
    return 0;
}