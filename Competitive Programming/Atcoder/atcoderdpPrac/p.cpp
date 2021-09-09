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
vector< vector< ll > > dp;
ll mod = 1e9+7;

void dfs(ll node, ll parent){
	for(int i = 0 ; i < adj[node].size() ; i++)
		if(adj[node][i] != parent){
			dfs(adj[node][i], node);
			dp[node][1] = (dp[node][1]*dp[adj[node][i]][0])%mod;
			dp[node][0] = (dp[node][0]*(dp[adj[node][i]][1] + dp[adj[node][i]][0])%mod)%mod;
		}
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    m = n-1;
    ginp;
    dp.resize(n+1, vector< ll > (2, 1));
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1])%mod << endl;
	return(0);
}