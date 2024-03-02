#include<bits/stdc++.h>
using namespace std;

int position_finder(vector<int>&arr , int low , int high){
    int pivot = arr[low];
    int i = low , j = high;
    
    while(i < j){
        while(arr[i] <= pivot && i <= (high-1)) i++;
        while(arr[j] > pivot && j >= (low+1)) j--;
        
        if(i<j) swap(arr[i] , arr[j]);
    }
    swap(arr[low] , arr[j]);
    return j ;
}

void quick_sort(vector<int>&arr , int low , int high){
    if(low < high){
        int position = position_finder(arr , low , high);
        quick_sort(arr , low , position-1);
        quick_sort(arr , position+1 , high);
    }
}


int main(){
     vector<int> arr = {3,4,7,10,2,4,3};
    quick_sort(arr , 0 , arr.size()-1); 
    for(auto it: arr) cout<<it<<" ";
}