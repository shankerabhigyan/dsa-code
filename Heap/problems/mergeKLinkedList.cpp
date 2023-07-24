// https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;

    Node(T val):data(val),next(nullptr){}
};

struct condition{
    constexpr bool operator()(
        Node<int>* const& a,
        Node<int>* const& b)
        const noexcept
    {
        return a->data < b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &la){
    priority_queue<Node<int>*, vector<Node<int>*>, condition> h;
    
}

int main(){

}