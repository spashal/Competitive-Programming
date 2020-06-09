#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k;
vector< ll > a;
vector< ll > b;
vector< ll > v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> k;
		ll s;
		ll ans = 0;
		for( int i = 0 ; i < n ; i++ ){
			cin >> s;
			a.push_back(s);
		}
		for( int i = 0 ; i < n ; i++ ){
			cin >> s;
			b.push_back(s);
		}
		sort( a.begin(), a.end(), greater< ll > ());
		sort( b.begin(), b.end(), greater< ll > ());
		for( int i = 0 ; i < k ; i++ ){
			v.push_back(b[i]);
			v.push_back(a[n-i-1]);
		}
		sort( v.begin(), v.end(), greater< ll > ());
		for( int i = 0 ; i < n - k ; i++ )
			ans += a[i];
		for( int i = 0 ; i < k ; i++ )
			ans += v[i];
		cout << ans << endl;
		a.clear();
		b.clear();
		v.clear();
	}
	return(0);
}