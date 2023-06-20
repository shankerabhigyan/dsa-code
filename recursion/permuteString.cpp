#include<bits/stdc++.h>
using namespace std; 

void permute(vector<char> v, vector<string> &ans, string temp){
    if(v.size()==0){
        ans.push_back(temp);
        return;
    }
    vector<char> copy = v;
    for(auto c:v){
        temp+=c;
        copy.erase(find(copy.begin(),copy.end(),c)); // find returns the iterator to the element to be deleted
        permute(copy,ans,temp);
        temp.pop_back();
        copy.push_back(c);
    }

}

int main(){
    vector<char> v;
    cout<<"Enter the string: ";
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        v.push_back(s[i]);
    }
    
    // arrange lexicograohically
    sort(v.begin(),v.end());

    vector<string> ans;
    string temp="";

    permute(v,ans,temp);
    sort(ans.begin(),ans.end());
    int count=0;
    cout << "Permutations are: " << endl;
    for(auto s:ans){
        cout<<s<<" ";
        count++;
    }
    cout<<endl;
    cout<<"Total permutations: "<<count<<endl;

    return 0;
}