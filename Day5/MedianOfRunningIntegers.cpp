#include <bits/stdc++.h>
using namespace std;

vector<float> getMedians(vector<vector<int> > &queries) {

    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int> > minh;

    vector<float> medians;

    for ( auto query:queries ) {

        if ( query[0]==0 ) {
            // Find Median
            float median;
            if ( maxh.size() == minh.size() ) {
                median = (maxh.top() + minh.top()) / 2.0;
            } else {
                median = minh.top();
            }
            medians.__emplace_back(median);
        
        } else {
            int num = query[1];
            minh.push(num);

            if ( minh.size()-maxh.size()>1 ) {

                maxh.push(minh.top());
                minh.pop();

            }
        } 

    }

    return medians;

}

int main() {

    vector<vector<int> > queries;
    vector<int> v(2,1);

    queries.push_back(v);
    v[0] = 1; v[1] = 5;
    queries.push_back(v);
    v[0] = 0;
    queries.push_back(v);

    v[0] = 1; v[1] = 6;
    queries.push_back(v);
    v[0] = 1; v[1] = 11;
    queries.push_back(v);
    v[0] = 1; v[1] = 4;
    queries.push_back(v);

    v[0] = 0;
    queries.push_back(v);

    v[0] = 1; v[1] = 17;

    queries.push_back(v);
    v[0] = 0;
    queries.push_back(v);

    for ( float m:getMedians(queries) )
        cout << m << " ";
    cout << endl;


}
