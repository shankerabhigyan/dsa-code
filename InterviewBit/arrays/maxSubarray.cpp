// https://www.interviewbit.com/problems/max-non-negative-subarray/
#include<bits/stdc++.h>
using namespace std;

void display(vector<int>&arr){
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> maxset(vector<int> &arr){
    vector<int> temp;
    vector<int> main;
    int mainsum=-1,tempsum=0;
    for(int i:arr){
        if(i<0){
            if(mainsum<tempsum){
                mainsum = tempsum;
                main = temp;
            }
            temp.clear();
            tempsum = 0;
        }
        else{
            tempsum += i;
            temp.push_back(i);
        }
    }
    if(tempsum>mainsum){
        return temp;
    }
    return main;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
    }
    vector<int> ans = maxset(arr);
    display(ans);
    return 0;
}