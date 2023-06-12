// sieve of erastothenes
// Time Complexity: O(n*log(log(n)))
// https://leetcode.com/problems/count-primes/
#include<bits/stdc++.h>
using namespace std;

int sieveOfErastothenes(int n){
    if (n<=2) return 0;
    vector<bool> arr(n-2,true); 
    int count=0;
    for (int i=2;i<n;i++){
        if(arr[i-2]){
            count++;
            for(int j=i*2;j<n;j+=i){
                arr[j-2]=false;
            }
        }
    }
    return count;
}

int main(){
    clock_t start, end;
    start = clock();
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    int ans = sieveOfErastothenes(n);
    cout << "Number of primes before " << n << " are : " << ans << endl;
    end = clock();
    // time taken in ms
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Runtime : " << fixed << time_taken << setprecision(5) << " sec " << endl;
}
