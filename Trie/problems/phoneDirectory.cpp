// https://www.codingninjas.com/studio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
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

// *****************************************************************************************************
// APPROACH 1 : (20 ms; <49%)

void getStrings(TrieNode* root, string curr, vector<string> &v){
    if(root->eow){
        v.push_back(curr);
    }
    for(int i=0;i<VOCAB_SIZE;i++){
        if(root->child[i]){
            char ch = 'a'+i;
            string s = curr + ch;
            getStrings(root->child[i],s,v);
        }
    }
    return;
}
// Time Complexity : O(n*m) where n is the number of words in the list and m is the length of the query (worst case)
vector<vector<string>> phoneDirectory(vector<string> &list, string &query){ 
    TrieNode* root = new TrieNode();
    for(string s:list){
        root->insertKey(s);
    }
    vector<vector<string>> ans;
    string s="";
    int i=0;
    while(i<query.size()){
        char ch = query[i];
        int index = ch-'a';
        s = s+ch;
        vector<string> v={};
        if(root->child[index]){
            getStrings(root->child[index],s,v);
            root = root->child[index];
            ans.push_back(v);
            i++;
            continue;
        }
        break;
    }
    vector<string> empty;
    if(i<query.size()){
        ans.push_back(empty);
        i++;
    }
    if(ans.size()==1 && ans[0].size()==0){
        vector<vector<string>> ans2;
        return ans2;
    }
    return ans;
}

// *****************************************************************************************************
// OPTIMISED SOLUTION : 

vector<vector<string>> phoneDirectoryOpt(vector<string> &list, string &query){
    
}




int main(){

    vector<string> list;
    cout << "Enter vocab" << endl;
    string s;
    cin >> s;
    while(s!="-1"){
        list.push_back(s);
        cin >> s;
    }

    string query;
    cout << "Enter Query : ";
    cin >> query;
    
    vector<vector<string>> v = phoneDirectory(list,query);

    for(auto x:v){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
