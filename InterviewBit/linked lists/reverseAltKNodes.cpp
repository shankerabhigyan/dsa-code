#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

void reverse(ListNode* head, ListNode* tail){
    if(head==tail) return;
    ListNode* curr = head->next;
    ListNode* prev = head;
    prev->next = nullptr;
    while(curr!=nullptr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return;
}

ListNode* solve(ListNode* A, int B){
    if(A->next==nullptr || B==1) return A;
    int length = 1;
    ListNode* temp = A;
    while(temp->next!=nullptr){
        length++;
        temp = temp->next;
    }
    int i=1;
    bool flag = true;
    temp = A;
    ListNode* next = A;
    ListNode* prev = nullptr;
    ListNode* head = nullptr;
    while(next!=nullptr){
        if(i==B){
            if(!flag){
                i=1;
                prev = next;
                temp = next->next;
                next = temp;
                flag=true;
            }
            else{
                ListNode* t = next->next;
                next->next = nullptr;
                reverse(temp,next);
                if(head!=nullptr){
                    prev->next = next;
                    temp->next = t;
                    temp = t;
                    next = t;
                    i=1;
                }
                else{
                    head = next;
                    temp->next = t;
                    next = t;
                    temp = next;
                    i=1;
                }
                flag=false;
            }
        }
        else{
            next = next->next;
            i++;
        }
    }
    return head;
}

int main(){
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    A->next->next->next->next = new ListNode(5);
    A->next->next->next->next->next = new ListNode(6);
    A->next->next->next->next->next->next = new ListNode(7);
    A->next->next->next->next->next->next->next = new ListNode(8);
    A->next->next->next->next->next->next->next->next = new ListNode(9);

    ListNode* head = solve(A, 3);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}