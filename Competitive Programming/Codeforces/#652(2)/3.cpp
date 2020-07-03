#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, k, inf = 1000000009, ninf = -1000000009, a[200005], mini[200005], maxi[200005], b[200005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < k ; i++ ) cin >> b[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}



int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		for(int i = 0 ; i < k ; i++){
			mini[i] = inf;
			maxi[i] = ninf;
		}
		ari;
		bri;
		ll ans = 0;
		sort(a, a + n, greater< ll > ());
		sort(b, b + k);
		// for(int i = 0 ; i < n ; i++)
		// 	cout << a[i] << "* ";
		int j = 0;
		for(int i = 0 ; i < k ; i++){
			if( b[i] == 1 ){
				maxi[i] = a[j];
				mini[i] = a[j];
			}
			else
				maxi[i] = a[j];
			j++;
		}
		for(int i = 0 ; i < k ; i++)
			if( mini[i] == inf ){
				mini[i] = a[j + b[i] - 2];
				j += b[i] - 1;
			}
		for(int i = 0 ; i < k ; i++){
			// cout << mini[i] << " " << maxi[i] << endl;
			ans += mini[i] + maxi[i];
		}
		cout << ans << endl;
	}
	return(0);
}
