//https://leetcode.com/problems/subsets-ii/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void findsubset(vector<int>& nums, vector<int>& temp_arr,
                    vector<vector<int>>& result, int index) {
        int n = nums.size();
        if (index >= n) {
            result.push_back(temp_arr);
            return;
        }
        temp_arr.push_back(nums[index]);
        findsubset(nums, temp_arr, result, index + 1);

        temp_arr.pop_back();
        while (index + 1 < n && nums[index] == nums[index + 1]) {
            index++;
        }
        findsubset(nums, temp_arr, result, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp_arr;
        vector<vector<int>> result;
        
        findsubset(nums, temp_arr, result, 0);
        return result;
    }
};

int main(){
    Solution s ;

    vector<int>nums = {1,2,2};
    vector<vector<int>> result = s.subsetsWithDup(nums);
    
    
    for (int i = 0; i < result.size(); i++) { 
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++) { 
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0 ; 
}