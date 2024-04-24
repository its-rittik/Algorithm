#include<bits/stdc++.h>

using namespace std;

int main(){
    int n  , m ;
    cin>>n>>m;

    vector<int> add_list[n+1];

    for(int i = 0 ; i< m ; i++){
        int u , v;
        cin>>u>>v;
        add_list[u].push_back(v);
        add_list[v].push_back(u);
    }

    for(int i = 0 ; i< n+1 ; i++){
        cout<<add_list[i]<<" --> ";
        for(int j = 0 ; j < add_list[i].size() ; j++){
            cout<<add_list[i][j]<<" ";
        }
        cout<<endl;
    }
}