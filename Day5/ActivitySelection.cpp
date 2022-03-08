#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b ) {

    if ( a[1] == b[1] ) {
        return a[0] < b[0];
    }
    return a[1] < b[1];

}

int solve(vector<vector<int> > times) {

    sort(times.begin(),times.end(),cmp);

    int currEndTime = 0, cnt = 0;

    for ( auto &activity:times ) {
        if ( currEndTime <= activity[0] ) {
            ++cnt;
            currEndTime = activity[1];
        }
    }

    return cnt;

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
