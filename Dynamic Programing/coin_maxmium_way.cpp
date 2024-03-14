#include<bits/stdc++.h>
using namespace std;

int coin_counter(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (index == 0) {
        if (target % coins[index] == 0) return 1;
        return 0;
    }
    if (dp[index][target] != -1) return dp[index][target];

    int not_take = coin_counter(index - 1, target, coins, dp);

    int take = 0; 

    if (target >= coins[index]) take = coin_counter(index, target - coins[index], coins, dp);

    return dp[index][target] = take + not_take;
}

int main() {
    int target = 8;
    vector<int> coins = {1, 3, 5};
    vector<vector<int>> dp(coins.size(), vector<int>(target + 1, -1));

    cout << "Maximum ways: " << coin_counter(coins.size() - 1, target, coins, dp) << endl;

    return 0;
}
