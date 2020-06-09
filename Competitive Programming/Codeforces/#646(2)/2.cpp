#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;

int main(){
	cin >> t;
	while( t-- ){
		char s[1005];
		ll k0[1005], k1[1005], l0[1005], l1[1005];
		cin >> s;
		n = strlen(s);
		if( s[0] == '0' ){
			k0[0] = 1;
			k1[0] = 0;
		}
		else{
			k0[0] = 0;
			k1[0] = 1;
		}
		for( int i = 1 ; i < n ; i++ ){
			if( s[i] == '0' ){
				k0[i] = k0[i-1] + 1;
				k1[i] = k1[i-1];
			}
			else{
				k0[i] = k0[i-1];
				k1[i] = k1[i-1] + 1;
			}
		}
		if( s[n-1] == '0' ){
			l0[n-1] = 1;
			l1[n-1] = 0;
		}
		else{
			l0[n-1] = 0;
			l1[n-1] = 1;
		}
		for( int i = n - 2 ; i > -1 ; i-- ){
			if( s[i] == '0' ){
				l0[i] = l0[i+1] + 1;
				l1[i] = l1[i+1];
			}
			else{
				l0[i] = l0[i+1];
				l1[i] = l1[i+1] + 1;
			}
		}
		// for( int i = 0 ; i < n ; i++ )
			// cout << k0[i] << " " << k1[i] << " " << l0[i] << " " << l1[i] << endl;
		ll ans = 100000;
		for( int i = 0 ; i < n - 1 ; i++ )
			ans = min( ans, min( k1[i] + l0[i+1], k0[i] + l1[i+1]));
		ans = min( ans, min( k0[n-1], k1[n-1]));
		cout << ans << endl;
	}
	return(0);
}