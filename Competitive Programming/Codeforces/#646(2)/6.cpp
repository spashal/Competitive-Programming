#include <bits/stdc++.h>
using namespace std;
vector< int > a;

void adjust( int i, int val, vector< int > &b){
    if( i == (int)b.size() )
        b.push_back(0);
    int temp = ( b[i] + val) / 10;
    b[i] = ( b[i] + val) % 10;
    if( ( b[i+1] + temp) > 9 )
        adjust( i+1, temp, b);
    else
        b[i+1] += temp;
}

void mult(){
    int na = (int)a.size();
    vector< int > b( 10000,0);
    for( int j = 0 ; j < na ; j++ ){
        for( int i = na - 1 ; i > -1 ; i-- ){
            if( ( b[i + j] + a[i] * a[j]) > 9 )
                adjust( i + j, a[i] * a[j], b);
            else
                b[i+j] += a[i] * a[j];
        }  
    }
    // for( int i = (int)(b.end() - b.begin() - 1) ; i > -1 ; i-- )
    //     cout << b[i];
    // cout << endl;

}

int main(){
    cin >> t1 >> t2 >> n;
    mult();
    return(0);
}