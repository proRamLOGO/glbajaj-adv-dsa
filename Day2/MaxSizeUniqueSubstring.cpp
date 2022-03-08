#include <bits/stdc++.h>
using namespace std;

string findMaxSizeUniqueSubstr(string s) {

    int front = 0;
    unordered_map<char,int> freq;
    freq[s[0]]++;

    string ans = "";

    for ( int rear = 1 ; rear < s.size() ; ++rear ) {

        if ( freq[s[rear]] != 0 ) {

            while ( front < rear && freq[s[rear]] != 0 ) {
                freq[s[front]]--;
                front++;
            }

        }

        if ( rear-front+1 > ans.length() ) {
            ans = s.substr(front, rear-front+1);
        }

        freq[s[rear]]++;

    }

    return ans;

}

int main() {

    string s;
    cin >> s;
    cout << findMaxSizeUniqueSubstr(s) << endl;


}

// 6
// 5 4 1 2 3 6