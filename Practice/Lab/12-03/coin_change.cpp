#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& coins, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] += dp[i - 1][j];
            if ((j - coins[i - 1]) >= 0) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    vector<int> coins{ 1, 2, 3 };
    int n = 3;
    int sum = 8;
    cout << count(coins, n, sum);
    return 0;
}


//

#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int n, int sum) {
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (n <= 0)
        return 0;
    return count(coins, n, sum - coins[n - 1]) + count(coins, n - 1, sum);
}

int main() {
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;
    cout << " " << count(coins, n, sum);
    return 0;
}
