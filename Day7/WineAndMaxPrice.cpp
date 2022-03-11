#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &v, int l, int r, int year, vector<vector<int> > &dp) {

    if ( r==l ) {

        for ( auto i:dp ) {
            for ( auto j:i )
                cout << j << ' ';
            cout << endl;
        }
        cout << endl;

        return dp[r][r] = v[r]*year;   
    }
    
    if ( dp[l][r] != -1 )
        return  dp[l][r];    

    dp[l][r] = min( v[l]*year + solve(v,l+1,r,year+1,dp)
        ,v[r]*year + solve(v,l,r-1,year+1,dp));
    
    for ( auto i:dp ) {
        for ( auto j:i )
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;

    return dp[l][r];

}

int main() {

    int n; cin >> n;
    vector<int> v(n);
    vector<vector<int> > dp(n,vector<int>(n,-1));
    for ( int &i:v ) cin>>i;
    
    cout << solve(v,0,n-1,1,dp) << endl;


}

// 5
// 2 4 6 2 5
// 5*1 =5
// 2*2 = 4
// 6*3 = 18
// 4*4 = 16
// 2*5 = 10
// 53

// dp[l][r]

// l = n-1, r=1

// dp[l-r][l-r+1]