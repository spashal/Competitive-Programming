#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
bool a[1000005];
vector< ll > prime;

int solve( ll a){
	int i;
	for( i = 0 ; ; i++ )
		if( a % prime[i] == 0 )
			break;
	return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for( int i = 2 ; i <= 1000000 ; i++ ){
    	if( !a[i] ){
	    	for( int j = 2 * i ; j <= 1000000 ; j += i )
    			a[j] = 1;
    		prime.push_back(i);
    	}
    }
    cin >> t;
	while( t-- ){
		ll k;
		cin >> n >> k;
		if( n % 2 == 0 )
			cout << n + k * 2 << endl;
		else
			cout << n + ( k - 1 ) * 2 + prime[solve(n)] << endl;
	}
	return(0);
}