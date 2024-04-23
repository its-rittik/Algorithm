#include<bits/stdc++.h>
using namespace std;

int knapsack(int index , int w , vector<int>& weight , vector<int>& value , vector<vector<int>>& dp){
    if(index == 0 ){
        if(weight[index] <= w) return value[index];
        return 0 ;
    }
    if(dp[index][w] != -1) return dp[index][w];

    int not_take = 0 + knapsack(index-1 , w , weight , value , dp);

    int take = INT_MIN;
    if(weight[index]<= w)
        take = value[index] + knapsack(index-1 , w - weight[index] , weight , value , dp);

    return dp[index][w] = max(not_take , take);
}

int main(){
    int w = 7;
    vector<int> weight = {3,2,5,2};
    vector<int> value = {30,40,60,45};

    int index = weight.size();

    vector<vector<int>> dp(index , vector<int> (w+1,-1)) ;

    cout<<"Max value you can take : "<<knapsack(index-1,w,weight,value, dp)<<endl;

    return 0 ;
}