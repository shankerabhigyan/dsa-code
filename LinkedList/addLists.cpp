#include<bits/stdc++.h>
using namespace std;
// sum 1->2->3 and 4->5 as 123 + 45 = 168

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}
};

void print(Node* &node){
    cout << node->val << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

void pad(Node* &head){
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    Node* node = new Node(0);
    temp->next = node;
}

Node* sumLists(Node* &head1, Node* &head2){
    Node* h1 = head1;
    Node* h2 = head2;
    Node* rev1 = NULL;
    Node* rev2 = NULL;
    while(h1 != NULL || h2 != NULL){
        if(h1 == NULL){
            pad(rev1);
            Node* node = new Node(h2->val);
            node->next = rev2;
            rev2 = node;
            h2 = h2->next;
            continue;
        }
        if(h2 == NULL){
            pad(rev2);
            Node* node = new Node(h1->val);
            node->next = rev1;
            rev1 = node;
            h1 = h1->next;
            continue;
        }
        Node* node = new Node(h1->val);
        node->next = rev1;
        rev1 = node;
        h1 = h1->next;
        node = new Node(h2->val);
        node->next = rev2;
        rev2 = node;
        h2 = h2->next;
    }
    //print(rev1);
    //print(rev2);
    int carry=0;
    Node* SUM = NULL;
    while(rev1 != NULL){
        int sum = rev1->val + rev2->val + carry;
        if(sum > 9){
            carry = 1;
            sum = sum % 10;
        }
        else{
            carry = 0;
        }
        Node* node = new Node(sum);
        node->next = SUM;
        SUM = node;
        rev1 = rev1->next;
        rev2 = rev2->next;
    }
    if(carry == 1){
        Node* node = new Node(1);
        node->next = SUM;
        SUM = node;
    }
    return SUM;
}

int main(){
    int a,b;
    cin >> a >> b;

    cout << "Enter the first list: ";
    Node* head1 = new Node();
    Node* tail1 = head1;
    cin >> head1->val;
    int x;
    for (int i = 1; i < a; i++){
        cin >> x;
        Node* node = new Node(x);
        tail1->next = node;
        tail1 = node;
    }

    cout << "Enter the second list: ";
    Node* head2 = new Node();
    Node* tail2 = head2;
    cin >> head2->val;
    for (int i = 1; i < b; i++){
        cin >> x;
        Node* node = new Node(x);
        tail2->next = node;
        tail2 = node;
    }

    Node* SUM = sumLists(head1, head2);
    print(SUM);


    return 0;
}