#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
vector< vector<ll> > dp(100005), limits(100005);	

ll dfs(int node, int parent, int limit){
	if(dp[node][limit] != -1)
		return dp[node][limit];
	if(parent != -1 and adj[node].size() == 1){
		dp[node][limit] = 0;
		return dp[node][limit];
	}
	dp[node][limit] = 0;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if(adj[node][i] != parent){
			dp[node][limit] += max(dfs(adj[node][i], node, limit) + llabs(limits[adj[node][i]][limit] - limits[node][limit]),
									dfs(adj[node][i], node, 1-limit) + llabs(limits[adj[node][i]][1-limit] - limits[node][limit]));
		}
	}
	return dp[node][limit];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			int u, v;
			cin >> u >> v;
			limits[i+1].pb(u);
			limits[i+1].pb(v);
			dp[i+1].pb(-1);
			dp[i+1].pb(-1);
		}
		m = n-1;
		ginp;
		cout << max(dfs(1, -1, 0), dfs(1, -1, 1)) << endl;
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
			dp[i].clear();
			limits[i].clear();
		}
	}
	return(0);
}