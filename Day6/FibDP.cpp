#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int fib(int n, vector<int>& dp) {
    if ( n<2 ){
        return n;
    }

    if ( dp[n]!=-1) {
        return dp[n];
    }
    
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

int main() {

    int n; cin >> n;
    vector<int> dp(n+1,-1);
    cout << fib(n,dp);
    for ( int i:dp )cout << i << ' ';
    cout << endl;


    // int x;
    
    // do {

    //     cin >> x;
    //     cout << (prime[x]?"YES":"NO");

    // } while(x!=-1);
    cout << endl << endl;

}