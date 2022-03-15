#include<iostream>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    int matrix[n][m];
    for ( int i = 0 ; i < n ; ++i)
        for ( int j = 0 ; j < m ; ++j)
            cin >> matrix[i][j];
    
    bool row=0,col=0;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( matrix[i][0] ) {
            col = true;
            break;
        }
    }
    for ( int i = 0 ; i < m ; ++i ) {
        if ( matrix[0][i] ) {
            row = true;
            break;
        }
    }


    for ( int i = 1 ; i < n ; ++i ) {
        for ( int j = 1 ; j < m ; ++j) {
            if ( matrix[i][j] == 0 ) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for ( int i = 1 ; i < n ; ++i ) {
        if ( matrix[i][0] == 0 ) {
            for ( int j = 1 ; j < m ; ++j ) {
                matrix[i][j] = 0;
            }
        }
    }
    for ( int i = 1 ; i < m ; ++i ) {
        if ( matrix[0][i] == 0 ) {
            for ( int j = 1 ; j < n ; ++j ) {
                matrix[j][i] = 0;
            }
        }
    }
    for ( int i = 0 ; col and i < m ; ++i ) {
        matrix[0][i] = 0;
    }
    for ( int i = 0 ; row  and i < n ; ++i ) {
        matrix[i][0] = 0;
    }

    for ( int i = 0 ; i < n ; ++i){
        for ( int j = 0 ; j < m ; ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;        
    }

}

// [[1,1,1]
// ,[1,0,1]
// ,[1,1,1]]

// 1 2 3 4 
// 5 0 7 8
// 0 10 11 12
// 13 14 15 0