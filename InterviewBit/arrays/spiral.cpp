#include<bits/stdc++.h>
using namespace std;

void spiralOrder(int is, int ie, int js, int je, const vector<vector<int>> &A, vector<int> &result){
    if(is>ie || js>je){
        return;
    }
    for(int j=js;j<=je;j++){
        result.push_back(A[is][j]);
    }
    for(int i=is+1;i<=ie;i++){
        result.push_back(A[i][je]);
    }
    if(is!=ie){
        for(int j=je-1;j>=js;j--){
            result.push_back(A[ie][j]);
        }
    }
    if(js!=je){
        for(int i=ie-1;i>is;i--){
            result.push_back(A[i][js]);
        }
    }
    spiralOrder(is+1,ie-1,js+1,je-1,A,result);
}

vector<int> spiralOrdermain(const vector<vector<int>> &A) {
    vector<int> result;
    spiralOrder(0,A.size()-1,0,A[0].size()-1, A, result);
    return result;
}

int main(){

    return 0;
}