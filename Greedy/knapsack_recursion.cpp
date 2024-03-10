#include<bits/stdc++.h>
using namespace std;

int knapsack(int index , int w , vector<int>& weight , vector<int>& value){
    if(index ==0){
        if(weight[index] <= w ) return value[index];
        return 0;
    }

    int not_take = 0 + knapsack(index-1 , w , weight , value);
    
    int take = INT_MIN;
    if(weight[index] <= w){
        take = value[index] + knapsack(index-1 , w-weight[index] , weight , value);
    }
    return max(not_take , take);
}


int main(){
    int w = 6;
    vector<int> weight = {3,2,5};
    vector<int> value = {30,40,60};

    cout<<"Max value you can take : "<<knapsack(weight.size()-1,w,weight,value)<<endl;
}