#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}
};

void InsertAtTail(Node* &tail, int val){
    Node* node = new Node(val);
    tail->next = node;
    tail = node;
}

void print(Node* &node){
    cout << node->val << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

void deleteHead(Node* &head){
    if(head==NULL){
        return;
    }
    if (head->next == NULL){
        delete head;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

Node* sort012(Node* head){
    Node* zeroh = new Node();
    Node* zerot = zeroh;

    Node* oneh = new Node();
    Node* onet = oneh;

    Node* twoh = new Node();
    Node* twot = twoh;

    while(head!=NULL){
        if(head->val==0){
            InsertAtTail(zerot,0);
        }
        else if(head->val==1){
            InsertAtTail(onet,1);
        }
        else if(head->val==2){
            InsertAtTail(twot,2);
        }
        head = head->next;
    }
    
    deleteHead(zeroh);
    deleteHead(oneh);
    deleteHead(twoh);

    zerot->next = oneh;
    onet->next = twoh;
    return zeroh;
}

int main(){
    Node* head=new Node(2);
    Node* tail=head;
    InsertAtTail(tail,1);
    InsertAtTail(tail,2);
    InsertAtTail(tail,0);

    print(head);
    Node* sorted = sort012(head);
    print(sorted);

}