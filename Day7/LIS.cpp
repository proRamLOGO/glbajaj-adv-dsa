#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &v, int idx) {

    int ans = 0;
    for ( int i = idx+1 ; i < v.size() ; ++i ) {
        if ( v[idx] < v[i] )
            ans = max(ans,solve(v,i));
    }
    return ans+1;

}

int main() {

    int n; cin >> n;
    vector<int> v(n);
    for ( int &i:v ) cin>>i;
    int ans = 0;
    for ( int i = 0 ; i < n ; ++i )
        ans = max(ans,solve(v,i));
    

}