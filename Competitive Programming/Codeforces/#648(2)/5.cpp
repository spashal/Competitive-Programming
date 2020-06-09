#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100005], n, m, t;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> n;
	ari;
	ll ans = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			for( int k = 0 ; k < n ; k++ )
				ans = max( ans, a[i] | a[j] | a[k]);
	cout << ans << endl; 
	return(0);
}