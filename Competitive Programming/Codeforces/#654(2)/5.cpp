#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[2005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int main(){
	vector< ll > final;
	cin >> n >> m;
	ari;
	sort(a, a + n);
	for(int x = 1 ; x <= a[n - 1] ; x++){
		ll ans = 1;
		for(ll i = 0 ; i < n ; i++){
			if( (a[i] - i) <= x )
				ans = min(i + 1, x + i - a[i] + 1);
			else
				ans = 0;
			if( ans % m == 0 )
				break;
		}
		if( ans % m )
			final.pb(x);
	}
	cout << (int)final.size() << endl;
	for(int i = 0 ; i < final.size() ; i++)
		cout << final[i] << " ";
	cout << endl;
	return(0);
}