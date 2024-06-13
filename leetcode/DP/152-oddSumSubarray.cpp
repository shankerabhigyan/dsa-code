#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int oddSumSubarrays(vector<int>& arr){
    int n  = arr.size();
    int even = 0, odd = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            swap(even, odd);
            odd++;
        }
        ans = (ans%1000000007 + odd%1000000007)%1000000007;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << oddSumSubarrays(arr) << endl;
}