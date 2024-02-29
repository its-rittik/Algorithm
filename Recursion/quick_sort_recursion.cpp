#include <bits/stdc++.h>
using namespace std ;

int partition_index(vector<int>&arr , int low , int high){
    int pivot = arr[low];
    int i = low ;
    int j = high ;

    while(i<j){
        while(arr[i] <= pivot && i <= (high-1)) i++;
        while(arr[j] > pivot && j >= (low+1)) j--;

        if(i<j) swap(arr[i] , arr[j]);
    }
    swap(arr[low] , arr[j]);

    return j;
}

void quick_sort(vector<int>&arr , int low , int high){
    if(low<high){
        int partition = partition_index(arr , low , high);
        quick_sort(arr,low,partition-1);
        quick_sort(arr,partition+1 ,high); 
    }
}

int main(){
    vector<int> arr = {3,2,1,5,6,4,7,10,2,4,3};
    quick_sort(arr , 0 , arr.size()-1);

    for(auto it: arr) cout<<it<<" ";
}