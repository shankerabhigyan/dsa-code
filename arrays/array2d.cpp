#include<bits/stdc++.h>
using namespace std; 
//https://stackoverflow.com/questions/12813494/why-do-we-need-to-specify-the-column-size-when-passing-a-2d-array-as-a-parameter

/*int search(int arr[][],n,m){

    return 0;

}*/
vector<int> rowWiseSum(int arr[][4],int n,int m){
    int sum=0;
    vector<int> rowsum;
    for (int i=0;i<n;i++){
        sum=0;
        for (int j=0;j<m;j++){
            sum+=arr[i][j];
        }
        rowsum[i]=sum;
    }
    return rowsum;

}

int main(){
    int n=3,m=4;
    //cout << "Enter the number of rows and columns : " << endl;
    //cin >> n >> m;
    int arr[n][m];

    cout << "Enter "<<(n*m)<< " elements of the array : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    /*cout << "The elements of the array are : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << "Row wise sum of the array is : " << endl;
    vector<int> rowsum=rowWiseSum(arr*[][4],n,m);
    for(auto i:rowsum){
        cout << i << " ";
    }
    return 0;
}