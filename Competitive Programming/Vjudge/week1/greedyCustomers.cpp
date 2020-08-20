#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
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
	cin >> n;
	ari;
	ll p = 2, ans = a[0] - 1, mini = 1000000009;
	for(int i = 1 ; i < n ; i++){
		if( a[i] == p )
			p++;
		ans += (a[i] - 1) / p;
	}
	cout << ans << endl;
	return(0);
}