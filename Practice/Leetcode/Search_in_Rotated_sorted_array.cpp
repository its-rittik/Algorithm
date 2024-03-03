//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std; 

int index_finder(vector<int>&temp , int target){
    for(int i = 0 ; i < temp.size() ;i++) if(target == temp[i]) return i;
    return -1;
}

int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1;
        int mid = (low+high)/2;       
        vector<int>temp = nums;
        
        sort(nums.begin(),nums.end());

        while(low <= high){
            if(nums[mid]==target) return index_finder(temp , target);
            else if(nums[mid]>target) high = mid-1;
            else  low = mid+1;
            
            mid = (low+high)/2;
        }
        return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    cout<<search(arr,0)<<endl;
}