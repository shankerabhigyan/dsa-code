#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* sortBinaryList(ListNode* A){
    ListNode* zeros = nullptr; ListNode* zeroshead = nullptr;
    ListNode* ones = nullptr; ListNode* oneshead = nullptr;
    while(A!=nullptr){
        if(A->val==0){  
            if(zeroshead==nullptr){
                zeros = A;
                zeroshead = A;
            }
            else{
                zeros->next = A;
                zeros = zeros->next;
            }
        }
        else{
            if(oneshead==nullptr){
                ones = A;
                oneshead = A;
            }
            else{
                ones->next = A;
                ones = ones->next;
            }
        }
        A = A->next;
    }
    zeros->next = oneshead;
    if(ones!=nullptr) ones->next = nullptr;
    return zeroshead;
}