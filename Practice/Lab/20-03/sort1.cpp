#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&value , vector<int>&weight , int capacity){
    
    vector<float>ratio(weight.size());

    for(int i= 0 ; i < weight.size() ; i++) ratio[i] = float(value[i]/weight[i]);

    for(int i = 0 ; i < weight.size() ; i++){
        for(int j = 0 ; j < weight.size()-1 ; j++){
            if(ratio[j] < ratio[j+1]){
                swap(ratio[j+1],ratio[j]);
                swap(weight[j+1] , weight[j]);
                swap(value[j+1] ,value[j]);
            }
        }    
    }
    int total_value = 0 ,i = 0;

    while(capacity>0){
        if(weight[i] <= capacity){
            capacity-=weight[i];
            total_value+=value[i];
            
        }
        i++;
    }

    return total_value;
}

int main(){
    vector<int> weight = {5,4,1,2,3};
    vector<int> value = {10,20,30,15,20};
    int capacity = 10;
    cout<<"\n"<<knapsack(value , weight, capacity);
}