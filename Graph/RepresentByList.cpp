#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int , int>> adj_list[n + 1]; 

    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    /*
    If the graph is a directed graph

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    */

   /*
   If the graph is a weighted undirected graph

    for(int i = 0; i < m; i++){
        int u, v , wt;
        cin >> u >> v >>wt;
        adj_list[u].push_back(make_pair(v,wt));
        adj_list[v].push_back(make_pair(u,wt));
    }

    for(int i = 1; i <= n; i++){ 
        cout << i << " --> ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j].first << " " <<adj_list[i][j].second << " , ";
        }
        cout << endl;
    }
   */

   
    for(int i = 1; i <= n; i++){ 
        cout << i << " --> ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}
