// https://www.codingninjas.com/studio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
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

    void deleteKey(string &key){
        TrieNode* curr = this;
        TrieNode* lastBranchNode = NULL;
        char lastBranchChar;
        for(auto ch:key){
            int index = ch-'a';
            if(!curr->child[index]){
                cout << "Key : \'" << key << "\' does not exist." << endl;
                break;
            }
            int count = 0;
            for(int i=0;i<VOCAB_SIZE;i++){
                if(curr->child[i]){
                    count++;
                }
            }
            if(count > 1){
                lastBranchNode = curr;
                lastBranchChar = ch;
            }
            curr = curr->child[index];
        }

        if(!curr->eow){
            cout << "Key : \'" << key << "\' does not exist." << endl;
        }
        else{
            // we need to account for three cases
            // 1. curr is not a leaf node and has children, i.e. it is a prefix of some other word
            // 2. curr shares a prefix with some other word
            // 3. curr is a leaf node and has no children neither does it share a prefix with some other word
            int count = 0;
            for(int i=0;i<VOCAB_SIZE;i++){
                if(curr->child[i]){
                    count++;
                }
            }

            if(count > 0){
                curr->eow = false;
            }
            else{
                if(lastBranchNode){
                    lastBranchNode->child[lastBranchChar-'a'] = NULL;
                }
                else{
                    delete this->child[key[0]-'a'];
                }
            }
        }
    }

    bool startsWith(string &prefix){
        TrieNode* curr = this;
        for(auto ch:prefix){
            int index = ch-'a';
            if(!curr->child[index]){
                return false;
            }
            curr = curr->child[index];
        }
        return true;
    }
};

int countChildren(TrieNode* &root){
    int count=0;
    for(int i=0;i<VOCAB_SIZE;i++){
        char ch = 'a'+i;
        if(root->child[i]!=NULL){
            count++;
        }
    }
    return count;
}
void getLCP(TrieNode* root, string &ans){
    int count = countChildren(root);
    if(count==1){
        for(int i=0;i<VOCAB_SIZE;i++){
            if(root->child[i]){
                ans = ans + char('a'+i);
                getLCP(root->child[i],ans);
                return;
            }
        }
    }
    return;
}

string longestCommonPrefix(vector<string> &arr, int n){
    TrieNode* root = new TrieNode();
    for(string key:arr){
        root->insertKey(key);
    }
    string s="";
    getLCP(root,s);
    return s;
}

int main(){
    vector<string> arr;
    string s;
    string ter("-1");
    cin >> s;
    while(s!=ter){
        arr.push_back(s);
        cin >> s;
    }

    cout << longestCommonPrefix(arr,arr.size()) << endl;

    return 0;
}

// kimrekacsf kimrettrwa kimreeybfg timrewwmnr kimretjxjl kimrejecjw 