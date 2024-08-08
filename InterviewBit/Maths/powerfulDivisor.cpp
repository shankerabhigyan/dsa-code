#include<bits/stdc++.h>
using namespace std;

bool isPower2(int n){
    return (n&(n-1))==0; // since n-1 will have all bits flipped from rightmost set bit of n
}

vector<int> countDivisors(int maxVal){
    vector<int> divisors(maxVal+1,0);
    for(int i=0;i<=maxVal;i++){
        for(int j=i;j<=maxVal;j+=i){
            divisors[j]++;
        }
    }
    return divisors;
}

vector<int> solve(vector<int> &A){
    int maxVal = *max_element(A.begin(),A.end());
    vector<int> divisors = countDivisors(maxVal);
    vector<int> powerOfTwoCounts(maxVal+1,0);
    for(int i=1;i<=maxVal;i++){
        if(isPower2(divisors[i])){
            powerOfTwoCounts[i] = 1;
        }
    }

    vector<int> prefixSums(maxVal+1,0);
    for(int i=1;i<=maxVal;i++){
        prefixSums[i] = prefixSums[i-1] + powerOfTwoCounts[i];
    }

    vector<int> result(A.size());
    for(int i=0;i<A.size();i++){
        result[i] = prefixSums[A[i]];
    }
    return result;
}

int main(){
    return 0;
}