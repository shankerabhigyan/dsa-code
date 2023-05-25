// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>
using namespace std;

double median(int arr1[], int arr2[], int n1, int n2){
    int arr[n1+n2];
    int k1=0,k2=0;
    for(int i=0;i<n1+n2-1;i++){
        if(arr1[k1]<arr2[k2] && k1<n1){
            arr[i]=arr1[k1];
            k1++;
        }
        else if(arr[k2]<arr[k1] && k2<n2){
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
    if((n1+n2)%2==0){
        return (arr[(n1+n2)/2]+arr[(n1+n2)/2-1])/2;
    }
    else{
        return arr[(n1+n2)/2];
    }
}

int main(){
    int n1,n2;
    cout << "Iput size of both arrays" << endl;
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

}