#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<vector<int>> arr, int target){
    int n = arr.size(); 
    int m = arr[0].size();
    int start = 0;
    int end = (n*m)-1,r,c;
    while(start<=end){
        int mid = start+ (end-start)/2;
        int r = mid/m, c=mid%m, el = arr[r][c];
         
        if(el==target){
            return mid; 
            break;
        }
        else if(el>target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1; // not found
}

int main(){
    int n,m;
    cout<<"Enter the number of rows and columns : "<< endl;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    // m is in () because it is the size of the vector inside the vector arr
    cout<<"Enter the elements of the array : "<< endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    cout<< "The array is : "<< endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter target element" << endl;
    int target;
    cin >> target;
    int mid =  binarySearch(arr,target);
    if(mid==-1){
        cout << "Element not found" << endl;
    }
    else{
        cout << "Element found at row " << mid/m +1 << " and column " << mid%m +1 << endl; 
    }

    return 0;
}