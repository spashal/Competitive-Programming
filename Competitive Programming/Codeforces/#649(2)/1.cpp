#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, x, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> x;
		vector< ll > ar;
		ari;
		ll div = 0;
		ll sum = 0;
		ar.push_back(-1);
		for( int i = 0 ; i < n ; i++ ){
			sum += a[i];
			if( a[i] % x == 0 ){
				div++;
				ar.push_back(i);
			}
		}
		// ll ma = -1;
		// for( int i = 1 ; i < ar.size() ; i++ )
		// 	ma = max( ma, ar[i] - ar[i-1] - 1);
		// if( a[n-1] % x != 0 )
		// ma = max(ma, n - ar[ar.size()-1] - 1 );
		if( sum % x != 0 )
			cout << n << endl;
		else if( ma == -1 )
			cout << n-1 << endl;
		else if( ma > 0 )
			cout << ma << endl;
		else
			cout << "-1" << endl;
		// cout << 0 % 2 << endl;
	}
	return(0);
}