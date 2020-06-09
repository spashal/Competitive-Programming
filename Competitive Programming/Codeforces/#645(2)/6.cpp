#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, x, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> x;
	vector< ll > mon, calc, d;
	for( int i = 0 ; i < n ; i++ ){
		cin >> m;
		mon.push_back(m);
	}
	ll ans = 0;
	calc.push_back(0);
	d.push_back(0);
	for( int i = 0 ; i < 2 * n ; i++ ){
		mon.push_back(mon[i]);
		calc.push_back( calc[i] + ( mon[i] * ( mon[i] + 1)) / 2 );
		d.push_back( d[i] + mon[i]);
	}
	for( int i = 0 ; i < 2 * n ; i++ ){
		if( d[ i + 1 ] >= x ){
			ll j = upper_bound( d.begin(), d.end(), d[ i + 1 ] - x) - d.begin();
			ll temp = calc[ i + 1 ] - calc[j];
			ll left = mon[ j - 1 ] - ( x - ( d[ i + 1 ] - d[j]));
			temp += ( ( mon[ j - 1 ] * ( mon[ j - 1 ] + 1)) / 2 - ( left * ( left + 1)) / 2);
			ans = max( temp, ans);
		}
	}
	cout << ans << endl;
	return(0);
}