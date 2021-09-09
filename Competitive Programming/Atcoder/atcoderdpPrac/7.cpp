#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); }
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
vector< ll > dp;
vector< bool > vis;
void dfs(int node){
	vis[node] = true;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if(!vis[adj[node][i]])
			dfs(adj[node][i]);
		dp[node] = max(dp[node], dp[adj[node][i]] + 1);
	}
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	ginp;
	vis.resize(n+1, false);
	dp.resize(n+1, 0);
	for(int i = 1 ; i <= n ; i++)
		if(!vis[i])
			dfs(i);
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return(0);
}