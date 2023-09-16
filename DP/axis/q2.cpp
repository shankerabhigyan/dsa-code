/*
Two groups
Given N student and M enemy relations. You need to divide these N students into 2 groups of equal sizes S such that no two students with direct enemy relations are in the same group. You need to maximize the value of S. Also, it is guaranteed that no student will have enemy relations with more than 2 students.
Notes

• S is the number of students in a single group.

• Both groups should have the same number

of students .i.e S.

Find the maximum possible value of S.

Function description

Complete the solve function. This function takes the following 3 parameters and returns the answer:

• N. Represents a number of students

• M. Represents the number of enemy

relations
N Represents a number of students

• M. Represents the number of enemy relations

⚫enemy. Represents the enemy relation

Input format for custom testing

Note: Use this input format if you are testing against custom input or writing code in a language where we don't provide boilerplate code.

The first line contains an integer N.

The second line contains an integer M.

• The next M line contains two space- separated integers, u, and v, representing the enemy relation between u and v.

Output format

Print the maximum possible value of S.

Constraints
1<M<N≤5 × 105
1≤u, v≤ N
Sample input
6
Sample output
4
*/

int minS(int n, int m, vector<vector<int>> enemy){
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        adj[enemy[i][0]].push_back(enemy[i][1]);
        adj[enemy[i][1]].push_back(enemy[i][0]);
    }
    vector<int> color(n+1,-1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            queue<int> q;
            q.push(i);
            color[i] = 0;
            int c0 = 1, c1 = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v:adj[u]){
                    if(color[v]==-1){
                        color[v] = 1 - color[u];
                        if(color[v]==0){
                            c0++;
                        }
                        else{
                            c1++;
                        }
                        q.push(v);
                    }
                    else if(color[v]==color[u]){
                        return -1;
                    }
                }
            }
            ans += max(c0,c1);
        }
    }
    return ans;
}
