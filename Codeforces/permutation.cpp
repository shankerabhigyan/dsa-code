#include<bits/stdc++.h>
using namespace std;

/*
You are given a positive integer n.
Find a permutation†
 p
 of length n
 such that there do not exist two distinct indices i
 and j
 (1≤i,j<n
; i≠j
) such that pi
 divides pj
 and pi+1
 divides pj+1
.

Refer to the Notes section for some examples.

Under the constraints of this problem, it can be proven that at least one p
 exists.

†
 A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).
*/

void display(vector<int>res){
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void getResult(vector<int>&arr, int s, int e){
    if(e-s<=2){
        return;
    }

    for(int i=0;i<=e-1;i++){
        for(int j=e-1;j>=0;j--){
            if(i==j){
                continue;
            }
            if(arr[j]%arr[i]==0 && arr[j+1]%arr[i+1]==0){
                swap(arr[i],arr[j+1]);
                getResult(arr,s+1,e-1);
                return;
            }
        }
    }
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        getResult(arr,0,n-1);
        display(arr);
    }

    return 0;
}