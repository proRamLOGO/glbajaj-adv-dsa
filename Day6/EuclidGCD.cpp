#include<bits/stdc++.h>
using namespace std;

unsigned long long int gcd(unsigned long long int a,unsigned long long int b) {
    if ( a>b ) swap(a,b);
    return ( a==0 ) ? b : gcd(b%a,a);
}

int main() {

    unsigned long long int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;

}