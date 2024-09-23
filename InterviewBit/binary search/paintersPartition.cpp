#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/painters-partition-problem/

# define LL long long
# define MOD 10000003

bool isFeasible(vector<int> &C, int A, int &B, LL mid){
    int sum = 0;
    for(int i=0;i<C.size();i++){
        sum += C[i];
        sum %= MOD;
        if(sum>mid){
            sum = C[i];
            A--;
        }
        if(A==0){
            return false;
        }
    }
    return true; 
}

int paint(int A, int B, vector<int>&C){
    if(C.size()==1) return C[0]*B;
    LL left = *max_element(C.begin(),C.end());
    LL right = accumulate(C.begin(),C.end(),0);
    while(left<right){
        LL mid = left + (right-left)/2;
        bool isf = isFeasible(C, A, B, mid);
        if(isf){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    return (left%MOD * B%MOD)%MOD;
}

int main(){
    int n, A, B;
    cout << "Enter the number of boards: ";
    cin >> n;
    vector<int> C(n);
    cout << "Enter the lengths of the boards: ";
    for(int i = 0; i < n; i++) {
        cin >> C[i];
    }
    cout << "Enter the number of painters: ";
    cin >> A;
    cout << "Enter the capacity of each painter: ";
    cin >> B;
    int result = paint(A, B, C);
    cout << "The minimum time to paint all boards is: " << result << endl;
    return 0;
}