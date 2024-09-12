#include<bits/stdc++.h>
using namespace std;

int getIndex(const vector<int>&A, int B){
    int s = 0;
    int e = A.size()-1;
    while(s<=e){
        int m = (s+e)/2;
        if(A[m]==B){
            return m;
        }
        else if(A[m]<B){
            s = m+1;
            continue;
        }
        else{
            e = m-1;
            continue;
        }
    }
    return -1;
}

int findCount(const vector<int> &A, int B){
    if(A.size()==0) return 0;
    int i = getIndex(A,B);
    if(i==-1) return 0;
    else{
        while(i>=0 && A[i-1]==B){
            i--;
        }
        i++;
        int count = 1;
        while(i<A.size() && A[i]==B){
            count++;
            i++;
        }
        return count;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int B;
    cin >> B;
    cout << findCount(A,B) << endl;
    
    return 0;
}