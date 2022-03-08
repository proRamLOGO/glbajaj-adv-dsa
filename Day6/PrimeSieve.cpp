#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

vector<bool> prime(1e6,1);

void __init__prime() {

    prime[0] = prime[1] = false;
    for ( ull num = 2 ; num < 1e6 ; ++num ) {
        // cout << num << endl;
        if ( prime[num] ) {
            // num is prime
            for ( ull fact = num*num ; 
                  fact < 1e6 ; 
                  fact += num ) {
                      prime[fact] = false;
                  }
        }
    }

}



int main() {

    __init__prime();
    cout << "SIEVE READY!!!\n\n";
    int x;
    
    do {

        cin >> x;
        cout << (prime[x]?"YES":"NO");

    } while(x!=-1);
    cout << endl << endl;

}