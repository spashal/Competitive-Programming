#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[200005], b[200005], f[200005];
vector< ll > adj[100005];
#define ari for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		for( int i = 1 ; i <= n ; i++ ){
			b[i] = 200005;
			f[i] = 0;
		}
		for( int i = 1 ; i <= n ; i++ ){
			if( f[a[i]] )
				b[a[i]] = min( b[a[i]], i - f[a[i]] + 1);
			f[a[i]] = i;
		}
		ll ans = 200005;
		for( int i = 1 ; i <= n ; i++ )
			ans = min(b[i], ans);
		if( ans == 200005 )
			cout << "-1" << endl;
		else
			cout << ans << endl;
 	}
	return(0);
}