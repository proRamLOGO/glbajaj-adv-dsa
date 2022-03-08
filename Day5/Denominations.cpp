#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b ) {

    if ( a[1] == b[1] ) {
        return a[0] < b[0];
    }
    return a[1] < b[1];

}

int solve(vector<int> denominations, int amount) {

    sort(denominations.begin(),denominations.end());

    int count = 0;
    for ( int i = denominations.size()-1 ; i > -1  ; --i) {

        count += amount/denominations[i];
        amount -= denominations[i]*(amount/denominations[i]);

    }
    return (amount)?-1:count;

}



int main() {

    int n;
    cin >> n;
    vector<vector<int> > times(n,vector<int>(2));

    for ( auto &v:times ) {
        cin >> v[0] >> v[1];
    }

    int ans = solve(times);
    cout << ans << endl;

}
