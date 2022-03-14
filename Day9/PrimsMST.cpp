#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, e;
    cin >> n >> e;
    vector<vector<int > > grp(n,vector<int>(n));

    for ( int i = 0 ; i < e ; ++i ) {

        int u,v,c;
        cin >> u >> v >> c;
        grp[u][v] = c;
        grp[v][u] = c;

    }

    unordered_map<int,bool>  map;
    vector<int> key(n,-1);
    key[0] = 0;

    for ( int i = 0 ; i < n-1 ; ++i ) {
        
        int minCost = INT_MAX, src = 0;
        for ( int ne = 0 ; ne < n ; ++ne ) {
            if ( !map[ne] ) {
                if ( key[ne]!=-1 and grp[ne][key[ne]] < minCost ) {
                    minCost = key[ne];
                    src = ne;
                }
            }
        }
        
        map[src] = true;

        for ( int ne = 0 ; ne < n ; ++ne ) {
            if ( map[ne] || grp[ne][src]==0 ) continue;

            if ( key[ne]==-1 || grp[ne][key[ne]] > grp[ne][src] ) {
                key[ne] = src;
            }

        }

    }

    for ( int i = 1 ; i < n ; ++i ) {
        cout << i << " - " << key[i] << " : " << grp[i][key[i]] << endl;
    }

}