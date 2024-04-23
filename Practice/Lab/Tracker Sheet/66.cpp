#include<bits/stdc++.h>
using namespace std;

unsigned long long knapsack(int maxWeight , vector<int>& weight , vector<int>& value , vector<vector<unsigned long long>>& dp){
    
    for(int W = weight[0] ; W <= maxWeight ; W++) dp[0][W] = value[0];

    for(int index = 1 ; index < weight.size(); index++){
        for(int W = 0 ; W <= maxWeight ; W++){

            unsigned long long not_take = 0 + dp[index-1][W];

            unsigned long long take = 0;

            if(weight[index]<= W)
                take = value[index] + dp[index-1][W - weight[index]];

            dp[index][W] = max(not_take , take);
        }
    }
    return dp[weight.size()-1][maxWeight]; 
}



int main(){
    int maxWeight , n ;

    cin>>maxWeight>>n;

    vector<int> weight(n);
    vector<int> value(n);

    for(int i = 0 ; i < n ; i++) cin>>value[i]>>weight[i];

    vector<vector<unsigned long long>> dp(weight.size() , vector<unsigned long long> (maxWeight+1,0));

    cout<<knapsack(maxWeight , weight , value , dp);

    return 0 ;
}