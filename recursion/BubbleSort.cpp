#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

vector<int> bubbleSort(vector<int> v){
    int n = v.size();
    while(n > 0){
        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){
                swap(&v[i],&v[i+1]);
            }
        }
        n--;
    }
    return v;
}

int main(){
    int n,x;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    vector<int> v1 = bubbleSort(v);
    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}