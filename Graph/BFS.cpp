#include <bits/stdc++.h>
using namespace std;

class Traversal{
    public:
    vector<int> breath_fast_search(int n ,int starting_node ,  vector<int>adj_list[]){
        vector<int> vis(n+1, 0);
        queue<int> q;
        
        q.push(starting_node);
        vis[starting_node] = 1;

        vector<int>bfs;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it:adj_list[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> adj_list[n + 1]; 

    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    Traversal T;
    vector<int> bfs = T.breath_fast_search(n,1,adj_list);

    cout<<"BFS: ";
    for(auto it:bfs) cout<<it<<" ";

    return 0;
}
