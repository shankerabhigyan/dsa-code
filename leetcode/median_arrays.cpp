// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<iostream>
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
    int n1,n2;
    cout << "Input size of both arrays" << endl;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    cout << "Input elements of array 1" << endl;
    for(int i=0; i<n1; i++){
        cin >> arr1[i];
    }
    cout << "Input elements of array 2" << endl;
    for(int i=0; i<n2; i++){
        cin >> arr2[i];
    }
    //double med =  median(arr1,arr2,n1,n2);
    cout << "Median of both arrays is: " << median(arr1,arr2,n1,n2) << endl;
    //check data type of med
    //cout << "Data type of med: " << typeid(median(arr1,arr2,n1,n2)).name() << endl;

    return 0;

}