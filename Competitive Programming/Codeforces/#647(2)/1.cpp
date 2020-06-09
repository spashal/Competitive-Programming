#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k, m, po[70];

int main(){
	cin >> t;
	po[0] = 1;
	for( int i = 1 ; i < 61 ; i++ )
		po[i] = po[i-1] * 2;
	while( t-- ){
		cin >> n >> m;
		int z = -1;
		ll a;
		if( max( n, m) % min( n, m) == 0 )
			a = max( n, m)/ min( n, m);
		else
			a = -1;
		for( int i = 0 ; i < 62 ; i++ ){
			if( a == po[i] ){
				z = i;
				break;
			}
		}
		if( z == -1 )
			cout << z << endl;
		else{
			if( z % 3 == 0 )
				cout << z / 3 << endl;
			else
				cout << z / 3 + 1 << endl;
		}
	}
	return(0);
}