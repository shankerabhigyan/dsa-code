//rough code
#include<iostream>
#include<vector>
using namespace std;

double median(int arr1[], int arr2[], int n1, int n2){
    int arr[n1+n2];
    int k1=0,k2=0;
    for(int i=0;i<n1+n2-1;i++){
        if(arr1[k1]<arr2[k2] && k1<n1){
            arr[i]=arr1[k1];
            k1++;
        }
        else if(arr2[k2]<arr1[k1] && k2<n2){
            arr[i]=arr2[k2];
            k2++;
        }
        else if(k1==n1){
            arr[i]=arr2[k2];
            k2++;
        }
        else if(k2==n2){
            arr[i]=arr1[k1];
            k1++;
        }
    }
    double ans;
    if((n1+n2)%2==0){
        ans = (arr[(n1+n2)/2]+arr[(n1+n2)/2-1])/2.0;
    }
    else{
        ans = arr[(n1+n2)/2]/1.0;
    }
    return ans;
}

int main(){
    vector<int> v;
    v.assign(2,1);
    int size = v.size();
    cout << "Size of vector: " << size << endl;
    cout << v[1] << endl; 
    int arr[2];
    arr[0]=v[0];
    arr[1]=v[1];
    // extract a vector reference & nums to a vector p
    // vector<int> p = nums;
    return 0;
}