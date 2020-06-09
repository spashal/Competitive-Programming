#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
int a[100005], b[100005], c[100005], d[100005];

int gcd( int a, int b){
	if( b == 0 )
		return a;
	return gcd( b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i];
	b[0] = a[0];
	c[ n - 1 ] = a[ n - 1 ];
	for( int i = 1 ; i < n ; i++ ){
		b[i] = gcd( a[i], b[ i - 1 ]);
		c[ n - i - 1 ] = gcd( a[ n - i - 1 ], c[ n - i ]);
	}
	d[0] = c[1];
	d[ n - 1 ] = b[ n - 2 ];
	for( int i = 0 ; i < n - 2 ; i++ )
		d[ i + 1 ] = gcd( b[i], c[ i + 2 ]);
	ll ans = d[0];
	for( int i = 1 ; i < n ; i++ )
		ans *= d[i]/c[0];
	cout << ans << endl;
	return(0);
}