#include <iostream>
#include <cmath>
using namespace std;
// find square root of a number using binary search

int sqrtInt(int n){
    int start = 0, end = n;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<end){
        int sq = mid*mid;
        if (sq == n)
        {
            return mid;
        }
        else if (sq >n){
            end = mid-1;
        }
        else{
            start = mid+1;
            ans = mid;
        }
        mid = start + (end-start)/2;
        //cout << "start: " << start << " end: " << end << " ans: " << ans << endl;
    }
    return ans;
}

float sqrtPrec(int n, int ansInt, int p){
    float ans = ansInt*1.0;
    // max precision is 6
    p = min(p,6);

    for (int i=1; i<=p; i++){

        while(ans*ans<=n){
            ans = ans + 1.0/pow(10,i);
        }
        ans = ans - 1.0/pow(10,i);
        cout << "ans: " << ans << endl;

    }
    return ans;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin>>n;
    int ansInt = sqrtInt(n);
    //cout<<ansInt<<endl;
    int p;
    cout << "Enter precision: ";
    cin>>p;
    float ans = sqrtPrec(n,ansInt,p);
    cout<<ans<<endl;
    return 0;
}