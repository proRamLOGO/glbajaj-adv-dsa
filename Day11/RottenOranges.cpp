#include<bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    vector<vector<bool> > grid(n, vector<bool>(m));
    queue<pair<int,int> > q;
    
    for ( int i = 0; i < n ; ++i )
        for ( int j = 0; j < m; ++j ) {
            int x; cin >> x;
            grid[i][j] = x;
            if ( grid[i][j]==0 ) {
                q.push({i,j});
            }
        }
    
    // i,j
    // i-1, j+0
    // i+1, j+0
    // i+0, j+1
    // i+0, j-1

    int dir[4][2] = {{-1, 0},
                     {+1, 0},
                     { 0,+1},
                     { 0,-1},};

    int ans = 0;
    while ( !q.empty() ) {

        int qs = q.size();

        while (qs--) {

            auto top = q.front(); q.pop();
            int x = top.first, y = top.second;

            for ( int i = 0 ; i < 4 ; ++i ) {
                int a = x+dir[i][0], b = y+dir[i][1];
                
                if ( !(a>-1 and a<n and b>-1 and b<m) || grid[a][b]==0 ) 
                    continue;

                grid[a][b] = 0;
                q.push({a,b});

            }

        }
        ++ans;

    }

    cout << ans-1 << endl;


}