#include <bits/stdc++.h>
using namespace std;


int maxSubArrSum(vector<int> &nums) {
    int maxAns = nums[0], candAns = 0;
    for ( int i:nums ) {

        candAns += i;
        if ( maxAns < candAns )
            maxAns = candAns;
        if ( candAns < 0 )
            candAns = 0;

    }
    return maxAns;
}


int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    
    for ( int &i:v )
        cin >> i;

    cout << maxSubArrSum(v) << endl;

}

// 7
// 5 7 1 -15 3 8 -7

// 7
// 5 7 1 -1 3 8 -7