#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, k;

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m >> k;
		ll ans;
		if( m <= n / k )
			ans = m;
		else if( m >= n - k + 2 )
			ans = 0;
		else if( ( m - n/k) % (k-1) == 0 )
			ans = n / k - (m - n/k)/(k-1);
		else
			ans = n / k - (m - n/k)/(k-1) - 1;
		cout << ans << endl;
	}
	return(0);
}