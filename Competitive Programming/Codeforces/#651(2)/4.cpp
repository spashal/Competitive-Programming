#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	t = 1;
	ll k;
	while( t-- ){
		cin >> n;
		ari;
		if( k == n ){
			ll max0 = 0, max1 = 0;
			for(int i = 0 ; i < n ; i += 2)
				max0 = max(max0, a[i]);
			for(int i = 1 ; i < n ; i += 2)
				max1 = max(max1, a[i]);
			cout << min(max0, max1) << endl;
		}
		else{
			sort(a, a + n);
			cout << a[0] << endl;
		}
	}
	return(0);
}	