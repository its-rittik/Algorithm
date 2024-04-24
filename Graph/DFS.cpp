#include <bits/stdc++.h>
using namespace std;

class Traversal{
    public:
        void dfs(int currentNode , vector<vector<int>>adj , vector<int> &visitedNode , vector<int> &dfsList){
            visitedNode[currentNode] = 1;
            dfsList.push_back(currentNode);
            
            for(int neighbor: adj[currentNode]){
                if(!visitedNode[neighbor]){
                    dfs(neighbor , adj , visitedNode , dfsList);
                }
            }
        }

        vector<int> DfsFinder(int n , int startingNode , vector<vector<int>>adj){
            vector<int> dfsList ;
            vector<int> visitedNode(n+1 , 0);

            visitedNode[0] = 1;

            dfs(startingNode , adj , visitedNode , dfsList);

            return dfsList;
        }
};


int main(){
    int n, sNode;
    cout<<"Enter the number of nodes : ";
    cin >> n;
    cout<<"Enter the value of starting Node :";
    cin>>sNode;

    cin.ignore();

    vector<vector<int>> adj_list(n + 1); 

    
    for (int i = 1; i <= n; i++) {
        cout<<"Adj list of "<<i<<" :";

        string line;
        getline(cin, line);
        istringstream iss(line);
        int node;
        while (iss >> node) {
            adj_list[i].push_back(node);
        }
    }
    
    Traversal T;
    vector<int> dfs = T.DfsFinder(n,sNode,adj_list);

    cout<<"DFS: ";
    for(auto it:dfs) cout<<it<<" ";

    return 0;
}
