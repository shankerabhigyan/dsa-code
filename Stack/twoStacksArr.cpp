// implement two stacks in an arr
// https://www.codingninjas.com/studio/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb

#include <bits/stdc++.h>
using namespace std;

class TwoStack{
    int* arr;
    int top1;
    int top2;
    int size;
    // for stack 1, insertion happens from the LHS
    // for stack 2, insertion happens from the RHS
    TwoStack(int size){
        this->size = size;
        top1=-1;
        top2=size;
        arr = new int[size];
    }

    void push1(int x){
        if(top2-top1>1){
            top1++;
            arr[top1] = x;
        }
        else{
            //cout << "Stack Overflow" << endl;
        }
    }

    void push2(int x){
        if(top2-top1>1){
            top2--;
            arr[top] = x;
        }
        else{
            //cout << "Stack Overflow" << endl;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};

int main(){

    return 0;
}