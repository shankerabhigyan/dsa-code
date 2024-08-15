#include<bits/stdc++.h>
using namespace std;

int pickFromBothSides(vector<int>&A, int B){
    int N = A.size();
    vector<int> prefixSum(B + 1, 0);
    vector<int> suffixSum(B + 1, 0);

    // Calculate prefix sums for the first B elements
    for (int i = 0; i < B; i++) {
        prefixSum[i + 1] = prefixSum[i] + A[i];
    }

    // Calculate suffix sums for the last B elements
    for (int i = 0; i < B; i++) {
        suffixSum[i + 1] = suffixSum[i] + A[N - 1 - i];
    }

    // Compute the maximum sum by picking elements from both ends
    int maxSum = INT_MIN;
    for (int i = 0; i <= B; i++) {
        int currentSum = prefixSum[i] + suffixSum[B - i];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main(){
    int n,b;
    cin >> n >> b;
    vector<int> V(n);
    for(int i=0;i<V.size();i++){
        cin >> V[i];
    }
    cout << pickFromBothSides(V,b) << endl;
    return 0;
}