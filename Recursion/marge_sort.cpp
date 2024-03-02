#include<bits/stdc++.h>
using namespace std;
void marge(vector<int>&arr , int low , int mid , int high){
    vector<int>temp;
    int left = low , right = mid+1 ;

    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i = low ; i <= high ; i++) arr[i] = temp[i-low];
}


void marge_sort(vector<int>&arr , int low , int high){
    int mid = (low+high)/2 ;
    if(low >= high)
        return;
    marge_sort(arr , low, mid);
    marge_sort(arr,mid+1, high);
    marge(arr,low, mid, high);
}

int main(){
    vector<int> arr = {1,4,2,5,6,3,9,8};
    marge_sort(arr , 0 , arr.size()-1);
    for(int i = 0 ; i < arr.size() ; i++) cout<<arr[i]<<" ";
}