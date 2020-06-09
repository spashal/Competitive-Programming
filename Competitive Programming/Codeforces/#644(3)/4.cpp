#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		int ans = 1000000002;
		cin >> n >> k;
		int sq = sqrt(n);
		for( int i = 1 ; i <= min( (int)k,sq) ; i++ )
			if( n % i == 0 ){
				if( max( (int)n/i, i) <= k )
					ans = min( ans, min( (int)n/i, i));
				else if( min( (int)n/i, i) <= k )
					ans = min( ans, max( (int)n/i, i));
			}
		cout << ans << endl;
	}
	return(0);
}