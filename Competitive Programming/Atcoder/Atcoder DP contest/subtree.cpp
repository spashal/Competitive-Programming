#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], mod;
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
vector< vector< ll > > dp;
bool vis[100005];
// ll fastExpo()

ll black(ll node, ll parent){
	// cout << node << " ";
	ll ans = 1;
	// cout << adj[node].size() << endl;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i] != parent ){
			black(adj[node][i], node);
			ans = (ans * (dp[adj[node][i]][0] + 1)) % mod;
		}
	// cout << "hippy" << node << " " << ans << endl;
	dp[node][0] = ans;
	return ans;
}

void udhar_chukta(ll node, ll parent){
	vis[node] = true;
	ll ans = 1;
	for(int i = 0 ; i < adj[parent].size() ; i++)
		if( adj[parent][i] != node )
			ans = (ans * (dp[adj[parent][i]][0] + 1)) % mod;
	if( ans == 1 )
		ans = dp[node][0];
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( !vis[adj[node][i]] )
			udhar_chukta(adj[node][i], node);
	dp[node][1] = (ans + dp[node][0]) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> mod;
    dp.resize(n + 1, vector< ll > (2));
    m = n - 1;
    ginp;
    // cout << "1" << endl;
    black(1, 0);
    // cout << "2" << endl;
    udhar_chukta(1, 0);
    dp[1][1]= dp[1][0];
    for(int i = 1 ; i <= n ; i++)
	    cout << dp[i][1] << " " << dp[i][0] << endl;
	return(0);
}