#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

vector<int> bubbleSort(vector<int> v){
    int n = v.size();
    if(n==0 || n==1){
        return v;
    }

    for(int i=0; i<n-1; i++){
        if(v[i]>v[i+1]){
            swap(&v[i],&v[i+1]);
        }
    }

    vector<int> smallVector(v.begin(), v.end()-1);
    vector<int> smallSortedVector = bubbleSort(smallVector);
    for(int i=0; i<n-1; i++){
        v[i] = smallSortedVector[i];
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