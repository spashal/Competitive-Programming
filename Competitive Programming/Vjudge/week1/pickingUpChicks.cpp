#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], v[55], d[55];
vector< ll > adj[100005];
#define dri for( int i = 0 ; i < n ; i++ ) cin >> d[i];
#define vri for( int i = 0 ; i < n ; i++ ) cin >> v[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int main(){
	cin >> t;
	ll j = 0;
	while( t-- ){
		ll k, b, T;
		cin >> n >> k >> b >> T;
		dri;
		vri;
		ll yet = 0;
		ll never = 0, swaps = 0;
		for(int i = n - 1 ; i > -1 ; i--){
			if( d[i] + v[i] * T < b )
				never++;
			else{
				yet++;
				swaps += never;
				if( yet == k )
					break;
			}
		}
		cout << "Case #" << ++j << ": ";
		if( yet < k )
			cout << "IMPOSSIBLE" << endl;
		else
			cout << swaps << endl;
	}
	return(0);
}