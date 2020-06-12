#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll a[100005], b[100005], c[100005], n, x[100005], y[100005], z[100005];
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i] >> b[i] >> c[i];
	z[0] = c[0];
	y[0] = b[0];
	x[0] = a[0];
	for( int i = 1 ; i < n ; i++ ){
		x[i] = a[i] + max( y[i-1], z[i-1]);
		y[i] = b[i] + max( x[i-1], z[i-1]);
		z[i] = c[i] + max( y[i-1], x[i-1]);
	}
	cout << max( x[n-1], max( y[n-1], z[n-1])) << endl;
	return(0);
}