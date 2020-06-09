#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k, total;
char s[1000005];
bool a[1000005];

ll solve( ll i){
	ll b = 0, v = 0;
	ll ans = 0, z = 0, f = 0;
	for( int j = i ; j <= n ; j += k ){
		if( z == 0 and a[j] ){
			z = j;
			f++;
		}
		else if( z ){
			if( !a[j] ){
				ans++;
				v = j;
			}
			else
				f++;
		}
	}
	if( v + k > n ){
		while( v > 0 and !a[v] ){
			ans--;
			v -= k;
		}
	}
	// cout << f << " " << ans << endl;
	if( z == 0 )
		return total;
	else
		return ( total - f)  + ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> k;
		total = 0;
		ll mina = 1000006;
		cin >> s;
		for( int i = 0 ; i < n ; i++ ){
			a[ i + 1 ] = s[i] - 48;
			// cout << a[i] << endl;
			total += a[ i + 1 ];
		}
		for( int i = 1 ; i <= k ; i++ ){
			// cout << solve(i) << "*";
			mina = min( mina, solve(i));
		}
		cout << mina << endl;
	}
	return(0);
}