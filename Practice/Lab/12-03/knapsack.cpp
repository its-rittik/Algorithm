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
    int w ;
    cout<<"enter the weight: ";
    cin>>w;

    int n ;
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<int>value(n);
    vector<int>weight(n);

    cout<<"Enter the the value : ";
    for(int i = 0 ; i < n ; i++) cin>>value[i];

    cout<<"Enter the the weight : ";
    for(int i = 0 ; i < n ; i++) cin>>value[i];

    vector<vector<int>> dp (n , vector<int>(w+1,-1));

    cout<<"Max value :"<<knapsack(n-1 , w , value , weight , dp);

    return 0 ;
}