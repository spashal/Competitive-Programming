#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
bool b[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	ll ai, bi, ans = 0, Q;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> m;
		a[m]++;
		b[m] = true;
	}
	cin >> Q;
	for(int i = 1 ; i <= 100000 ; i++)
		if( b[i] )
			ans += i * a[i];
	for(int i = 0 ; i < Q ; i++){
		cin >> ai >> bi;
		ans += (bi - ai) * a[ai];
		b[ai] = false;
		a[bi] += a[ai];
		a[ai] = 0;
	cout << ans << endl;
	}
	return(0);
}