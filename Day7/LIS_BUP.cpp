#include<iostream>
#include<vector>

using namespace std;

// int solve(vector<int> &v, int idx) {

// }

int main() {

    int n; cin >> n;
    vector<int> v(n),dp(n,1);
    for ( int &i:v ) cin>>i;
    
    // dp[n-1] = 1;
    for ( int i = n-1 ; i > -1; --i ) {
        for ( int j = i+1 ; j < n ; ++j ) {
            if ( v[i] < v[j] ) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    cout << *max_element(dp.begin(),dp.end()) << endl;


}

// 8
// 2 5 1 3 4 7 9 11