#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
double ans[100005];
ll t, n;
bool vis[100005];
vector< ll > adj[100005];

double dfs( ll a){
	vis[a] = true;
	ll k = 0;
	ans[a] = 0;
	for( int i = 0 ; i < adj[a].size() ; i++ )
		if( !vis[adj[a][i]] ){
			k++;
			ans[a] += dfs( adj[a][i]);
		}
	if( k != 0 ){
		ans[a] = (double)ans[a]/k;
		ans[a] += 1;
	}
	return ans[a];
}

int main(){
	cin >> n;
	for( int i = 0 ; i < n - 1 ; i++ ){
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs( 1);
	cout << fixed << setprecision(6) << ans[1] << endl;
	return 0;
}