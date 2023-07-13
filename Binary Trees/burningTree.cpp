// https://practice.geeksforgeeks.org/problems/burning-tree/1
// find minimum time required to burn the given BT and a target.
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int val): val(val), right(nullptr), left(nullptr){}
};

node* buildFromLevelOrder(){
    queue<node*> q;
    cout << "Enter root value : ";
    int data;
    cin >> data;
    node* root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            continue;
        }
        node* left;
        node* right;

        cout << "Enter left node value for " << temp->val << " : ";
        cin >> data;
        if(data!=-1){
            left = new node(data);
        }
        else{
            left = NULL;
        }
        cout << "Enter right node value for " << temp->val << " : ";
        cin >> data;
        if(data!=-1){
            right = new node(data);
        }
        else{
            right = NULL;
        }
        temp->left = left;
        temp->right = right;
        q.push(left);
        q.push(right);
    }
    return root;
}

// solution 1: O(n) + O(n) = O(n)
int createMapping(node* root, unordered_map<int, pair<int,int>> &m){
    if(root==NULL){
        return 0;
    }

    int left = createMapping(root->left, m);
    int right = createMapping(root->right,m);

    m[root->val] = {left,right};

    return max(left,right)+1;
}

pair<int,int> burnTree(node* root, int target, unordered_map<int,pair<int,int>> m){
    if(root==NULL){
        return {0,0};
    }

    if(root->val == target){
        return {1, max(m[root->val].first, m[root->val].second)-1};
    }

    pair<int,int> left = burnTree(root->left, target, m);
    pair<int,int> right = burnTree(root->right, target, m);

    if(left.first!=0){
        return {left.first+1, max(left.second, m[root->val].second)-1};
    }

    if(right.first!=0){
        return {right.first+1, max(right.second,m[root->val].first)-1};
    }

    return {0,0};

}


int minTime(node* root, int target){
    unordered_map<int,pair<int,int>> m;
    createMapping(root, m);
    pair<int,int> p = burnTree(root,target,m);
    return p.first + max(0,p.second); 
}


// solution 2: O(n) {accepted on gfg}

int findDepth(node* root){
    if(root==NULL){
        return 0;
    }

    return max(findDepth(root->left), findDepth(root->right))+1;
}

bool getBurnTime(node* root, int target, pair<node*,node*> &p){ // O(n)
    if(root==NULL){
        return false;
    }

    if(root->val == target){
        p.first = root;
        p.second = NULL;
        return true;
    }

    if(root->left && root->left->val == target){
        //p.first = root;
        p.second = root->left;
        node* temp = new node(target);
        temp->left = root;
        temp->right = NULL;
        p.first = temp;
        root->left = NULL;
        return true;
    }

    if(root->right && root->right->val == target){
        //p.first = root;
        p.second = root->right;
        node* temp = new node(target);
        temp->left = root;
        temp->right = NULL;
        p.first = temp;
        root->right = NULL;
        return true;
    }

    bool left = getBurnTime(root->left, target, p);
    bool right = getBurnTime(root->right, target, p);

    if(left){
        if(root->left->right == NULL){
            root->left->right = root;
            root->left = NULL;
        }
        else{
            root->left->left = root;
            root->left = NULL;
        }
        return true;
    }

    if(right){
        if(root->right->right == NULL){
            root->right->right = root;
            root->right = NULL;
        }
        else{
            root->right->left = root;
            root->right = NULL;
        }
        return true;
    }

    return false;
}

int solve(node* root, int target){
    pair<node*,node*> p;
    getBurnTime(root, target, p);
    return max(findDepth(p.first), findDepth(p.second))-1;
}

// solution 3: {codehelp approach} O(n) + O(n) = O(n)
// creates a mapping of parent and child nodes and returns target node
node* createParentMapping(node* root, int target, unordered_map<node*,node*> &m){
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    m[root] = NULL;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp->val == target){
            res = temp;
        }
        if(temp->left){
            q.push(temp->left);
            m[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            m[temp->right] = temp;
        }
    }
    return res;
}

int BurnTree(node* root, unordered_map<node*,node*> &m){
    int ans = 0;
    unordered_map<node*, bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root] = true;
    bool flag = false;
    while(!q.empty()){
        int size = q.size();

        for(int i=0;i<size;i++){
            node* temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left] = true;
                flag = true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right] = true;
                flag = true;
            }
            if(m[temp] && !visited[m[temp]]){
                q.push(m[temp]);
                visited[m[temp]] = true;
                flag = true;
            }
        }
        if(flag){
            ans++;
            flag = false;   
        }
    }
    return ans;
}

int Solve(node* root, int target){
    unordered_map<node*,node*> m;
    node* targetNode = createParentMapping(root, target, m);
    return BurnTree(targetNode, m);
}

int main(){
    int target;
    cin >> target;
    node* root = buildFromLevelOrder();
    //int ans = solve(root, target); // time taken on gfg : 0.03s
    int ans = Solve(root, target); // time taken on gfg : 0.09s
    cout << ans << endl;
    return 0;
}