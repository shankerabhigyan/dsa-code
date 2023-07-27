#include<bits/stdc++.h>
using namespace std;

#define VOCAB_SIZE 26

struct TrieNode{
    struct TrieNode* child[VOCAB_SIZE];
    bool eow; // end of word flag
    TrieNode(){
        eow = false;
        for(int i=0;i<VOCAB_SIZE;i++){
            child[i] = NULL;
        }
    }

    void insertKey(string &key){
        TrieNode* curr = this;
        for(auto ch:key){
            int index = ch-'a';
            if(curr->child[index] == NULL){
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->eow = true;
    }

    bool searchKey(string &key){
        TrieNode* curr = this; // this points to the current object
        for(auto ch:key){
            int index = ch-'a';
            if(curr->child[index] == NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return curr->eow;
    }
};

int main(){
    vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    TrieNode* root = new TrieNode();
    for(auto key:keys){
        root->insertKey(key);
    }

    string key;
    cout << "Enter the key to search: ";
    cin >> key;
    cout << '\'' << key << '\'' << " is " << (root->searchKey(key) ? "present" : "not present") << endl;

    return 0;
}