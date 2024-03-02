#include<bits/stdc++.h>
using namespace std;

int bubble_sort(vector<int>&arr){
    bool checker = true;
    for(int i = 0 ; i< arr.size(); i++){
        for(int j  = 0 ; j < arr.size()-1 ; j++) 
            if(arr[j] > arr[j+1]){ 
                swap(arr[j] , arr[j+1]);
                checker = false;
            } 
        if(checker) break;
    }
}

int main(){
    vector<int>arr ={1,2,4,3,7,6,5};
    bubble_sort(arr);

    for(int i = 0 ; i < arr.size(); i++) cout<<arr[i]<<" ";
    return 0 ;
}