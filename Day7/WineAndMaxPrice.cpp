#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &v, int l, int r, int year, vector<vector<int> > &dp) {

    if ( r==l )
        return v[r]*year;
    
    if ( dp[l][r] != -1 )
        return  dp[l][r];    

    return dp[l][r] = min( v[l]*year + solve(v,l+1,r,year+1,dp)
        ,v[r]*year + solve(v,l,r-1,year+1,dp));

}

int main() {

    int n; cin >> n;
    vector<int> v(n);
    vector<vector<int> > dp(n,vector<int>(n,-1));
    for ( int &i:v ) cin>>i;
    
    cout << solve(v,0,n-1,1,dp) << endl;


}


