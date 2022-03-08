#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    
    for ( int &i:v )
        cin >> i;

    unordered_map<int,int> freq;

    for ( int &i:v ) {
        freq[i] = freq[i] + 1;
    }

    for ( auto itr:freq ) {
        cout << itr.first << " : " << itr.second << endl;
    }

}

// 6
// 5 4 1 2 3 6