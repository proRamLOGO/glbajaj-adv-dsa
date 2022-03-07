#include <bits/stdc++.h>
using namespace std;

int minCostToJoinRopes(vector<int> &v) {

    priority_queue<int,vector<int>,greater<int> > pq;

    for ( int &i:v )
        pq.push(i);
    
    int cost = 0;

    while ( pq.size()>1 ) {
        cout << cost << ", ";
        int r1 = pq.top();
        pq.pop();
        int r2 = pq.top();
        pq.pop();
        cost += r1+r2;
        cout << cost << ", \n";
        pq.push(r1+r2);
    }

    return cost;

}

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for ( int &i:v ) cin >> i;

    cout << minCostToJoinRopes(v) << endl;

}
