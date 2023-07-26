// https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;

    Node(T val):data(val),next(NULL){}
};

struct condition{ 
    constexpr bool operator()(
        Node<int>* const& a,
        Node<int>* const& b)
        const noexcept
    {
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &la){ 
    if(la.size() == 0){
        return NULL;
    }
    priority_queue<Node<int>*, vector<Node<int>*>, condition> pq;
    for(int i=0;i<la.size();i++){
        if(la[i]){
            pq.push(la[i]);
        }
    }
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    while(!pq.empty()){
        Node<int>* temp = pq.top();
        pq.pop();
        if(temp->next){
            pq.push(temp->next);
        }
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    return head;
}

int main(){
    vector<Node<int>*> la;
    Node<int>* h1 = new Node(-8);
    h1->next = new Node(-5);
    h1->next->next = new Node(3);
    h1->next->next->next = new Node(7);
    la.push_back(h1);

    Node<int>* h2 = new Node(-7);
    h2->next = new Node(6);
    h2->next->next = new Node(10);
    la.push_back(h2);

    Node<int>* h3 = new Node(-10);
    h3->next = new Node(-5);
    h3->next->next = new Node(2);
    h3->next->next->next = new Node(6);
    h3->next->next->next->next = new Node(7);
    la.push_back(h3);

    Node<int>* h4 = new Node(3);
    la.push_back(h4);
    
    Node<int>* ans = mergeKLists(la);

    cout << endl<<"ans" << endl;
    while(ans){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}