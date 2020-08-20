#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], mod = 998244353;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

ll binexp(ll a){
	ll c = 2;
	ll ans = 1;
	while(a){
		if( a % 2 )
			ans = (ans * c) % mod;
		c = (c * c) % mod;
		a /= 2;
	}
	return ans;
}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		cout << binexp(n - (n / m)) << endl;
	}
	return(0);
}