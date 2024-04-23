#include<bits/stdc++.h>
using namespace std;

int knapsack(int maxWeight , vector<int>& weight , vector<int>& value , vector<vector<int>>& dp){
    
    for(int W = weight[0] ; W <= maxWeight ; W++) dp[0][W] = value[0];

    for(int index = 1 ; index < weight.size()-1 ; index++){
        for(int W = 0 ; W < maxWeight ; W++){

            int not_take = 0 + dp[index-1][W];

            int take = INT_MIN;

            if(weight[index]<= W)
                take = value[index] + dp[index-1][W - weight[index]];

            return dp[index-1][maxWeight];
        }
    }
}


int main(){
    int maxWeight = 7;
    vector<int> weight = {3,2,5,2};
    vector<int> value = {30,40,60,45};

    vector<vector<int>> dp(weight.size() , vector<int> (maxWeight+1,0)) ;

    cout<<knapsack(maxWeight , weight , value , dp);

    return 0 ;
}