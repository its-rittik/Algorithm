#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&arr){
    bool checker = true ;
    
    for(int i = 0 ; i < arr.size()-1 ; i++){
        int lowest_number_position = i;
        for(int j = i ; j < arr.size() ; j++)
            if(arr[j] <= arr[lowest_number_position]){
                lowest_number_position = j;
                checker = false;
            }
        swap(arr[i] ,arr[lowest_number_position]);
        if(checker) break;
    }
        
}

int main(){
    vector<int>arr ={1,2,4,3};
    selection_sort(arr);

    for(auto it:arr) cout<<it<<" ";
    return 0 ;
}