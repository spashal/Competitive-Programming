#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k, m, po[65];

int main(){
	cin >> t;
	po[0] = 1;
	for( int i = 1 ; i < 61 ; i++ )
		po[i] = po[i-1] * 2;
	while( t-- ){
		cin >> n;
		ll ans = 0;
		for( int i = 0 ; i < 61 ; i++ )
			ans += n / po[i];
		cout << ans << endl;
	}
	return(0);
}