#include <bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int> &nums) {

    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    ans[n-1] = -1;
    s.push(nums[n-1]);

    for ( int i = n-2 ; i > -1 ; --i ) {

        // 1. Get Stack Ready
        while ( !s.empty() && s.top()<nums[i] )
            s.pop();
        
        // 2. Get ans
        ans[i] = (s.empty()) ? -1 : s.top();

        // 3. Get stack ready for next iteration
        s.push(nums[i]);

    }

    return ans;

}


int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    
    for ( int &i:v )
        cin >> i;

    vector<int> ans = nextGreaterElement(v);

    for ( int &i:ans )
        cout << i << ' ';

    cout << endl;

}

// 6
// 5 4 1 2 3 6