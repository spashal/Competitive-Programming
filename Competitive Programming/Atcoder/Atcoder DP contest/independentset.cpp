#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, dp[100005][2], mod = 1000000007;
bool onw[100005], onb[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < n - 1 ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int black(int node);

int white(int node){
	if( dp[node][0] )
		return dp[node][0];
	onw[node] = true;
	dp[node][0] = 1;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if( !onw[adj[node][i]] and !onb[adj[node][i]] )
			dp[node][0] = (dp[node][0] * (white(adj[node][i]) + black(adj[node][i])) % mod) % mod;
	onw[node] = false; 
	return dp[node][0];
}

int black(int node){
	if( dp[node][1] )
		return dp[node][1];
	onb[node] = true;
	dp[node][1] = 1;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		if( !onw[adj[node][i]] and !onb[adj[node][i]] )
			dp[node][1] = (dp[node][1] * white(adj[node][i])) % mod;
	onb[node] = false;
	return dp[node][1];
}

int main(){
	cin >> n;
	ginp;
	int last = 0;
	if( n == 1 ){
		cout << "2" << endl;
		return(0);
	}
	cout << (black(1) + white(1)) % mod << endl;
	return(0);
}