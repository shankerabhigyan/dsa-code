//problem - find the first and last index of an element in a sorted array
#include<iostream>
using namespace std;

int binarySearchfirstOcc(int arr[],int size, int element){
    int start = 0;
    int end = size-1;
    int store = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==element){
            store = mid;
            end = mid-1;
        }
        else if(arr[mid]>element){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return store;
}

int main(){
    //int T;
    //cin >> T;
    //NOTE this code is for a single test case
    int N,K;
    cin >> N >> K;
    int arr[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int start = binarySearchfirstOcc(arr, N, K); // first occurence
    // us elinear search
    int end = start;
    while(arr[end]==K){
        end++;
    }
    end--;
    cout << "First occurence at index: " << start << endl;
    cout << "Last occurence at index: " << end << endl;
    
    return 0;
}