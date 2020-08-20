#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	ll pre = n * m, mod = 1000000007, ans = 0;
	m = min(n, m);
	for(int i = 1 ; i * i <= n ; i++){
		ans += i * (n / i);
		ans += i * (n / i - (n + i) / (i + 1) + 1);
		ans %= mod;
	}
	cout << (pre - ans) % mod << endl;
	return(0);
}