//https://vjudge.net/contest/362664#problem/A
#include<bits/stdc++.h>
using namespace std;

unsigned long long  knapsack(int index , int w , vector<int>& weight , vector<int>& value , vector<vector<unsigned long long >>& dp){

    if(index == 0 ){
        if (w >= weight[index]) return (unsigned long long )value[index];
        return 0 ;
    }

    if(dp[index][w] != -1) return dp[index][w];

    unsigned long long not_take = 0+ knapsack(index-1 , w , weight , value , dp);

    unsigned long long take = 0;

    if(w>= weight[index]) take = value[index] + knapsack(index-1 , w - weight[index] , weight , value ,dp);

    return dp[index][w] = max(not_take , take);
}


int main(){
    int n , w;
    cin>>n>>w;

    vector<int> weight(n);
    vector<int> value(n);
    

    vector<vector<unsigned long long >> dp (n , vector<unsigned long long > (w+1 , -1));

    for(int i = 0 ; i< n ; i++) cin>>weight[i]>>value[i];

    cout<<knapsack(n-1,w , weight , value , dp);
}