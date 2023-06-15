#include<bits/stdc++.h>
using namespace std;

void display(int** arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    display(arr,n,m);

    """
    Delete the array from the heap.
    """
    for(int i=0;i<n;i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}