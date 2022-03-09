#include<iostream>
#include<vector>

using namespace std;

int solve(int num, vector<int> &dp) {

    if ( dp[num]!=-1 )
        return dp[num];

    cout << num << endl;

    int ans = INT_MAX;

    if ( num%3==0 )
        ans = min(ans,solve(num/3,dp));
    if ( num%2==0 )
        ans = min(ans,solve(num/2,dp));
    
    ans = min(ans,solve(num-1,dp));

    return dp[num] = ans+1;

}



int main() {

    int n; cin >> n;
    vector<int> dp(n+1,-1);
    dp[1] = 0;
    cout << solve(n,dp) << endl;

}