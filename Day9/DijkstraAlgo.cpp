#include<bits/stdc++.h>
using namespace std;

int main() {


    int n, e, src;
    cin >> n >> e >> src;
    vector<vector<int > > grp(n,vector<int>(n));

    for ( int i = 0 ; i < e ; ++i ) {

        int u,v,c;
        cin >> u >> v >> c;
        grp[u][v] = c;
        grp[v][u] = c;

    }

    unordered_map<int,bool> map;
    vector<int> key(n,INT_MAX);
    key[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    pq.push({0,src});

    for ( int i = 0 ; i < n-1 ; ++i ) {

        pair<int,int> top = pq.top(); pq.pop();
        int dist = top.first, u = top.second;

        for ( int i = 0 ; i < n ; ++i ) {
            if ( grp[i][u] == 0 ) continue;

            if ( key[i] > dist+grp[i][u] ) {
                key[i] = dist+grp[i][u];
                pq.push({key[i],i});
            }

        }

    }

    for ( int i = 0 ; i < n ; ++i ) {
        cout << i << " : " << key[i] << endl;
    }

}
// 5 6 3
// 0 1 5
// 1 2 2
// 0 3 7
// 1 3 1
// 3 4 3
// 2 4 2