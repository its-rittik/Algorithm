//https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>
using namespace std;

int convert_into_digits(int i , vector<int>&digits){
    while(i!=0){
        digits.push_back(i%10);
        i/=10;
    }
    return digits.size();
}

int main(){
    int n;
    cin>>n;

    vector<int>dp(n+1,1e9);
    //dp[i] = minimum way to make i to 0

    //base case
    dp[0] = 0;

    for(int i =1 ; i<=n ; i++){
        vector<int> digits;
        
        //breaking the number into digits . for example 10 -> 1,0
        int length = convert_into_digits(i , digits);

        for(int j = 0 ; j<length ; j++){
            //tanstion
            if(digits[j]!=0) dp[i] = min(dp[i] , dp[i-digits[j]] +1);
           
        }
        //empty the digits vector
        digits.erase(digits.begin() , digits.end());
    }
    //fianl problem
    cout<<dp[n]<<endl;

}