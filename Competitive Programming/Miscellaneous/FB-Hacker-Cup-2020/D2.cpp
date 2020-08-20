#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < n - 1 ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair

void dfs(int node){
	vis[node] = true;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( !vis[adj[node][i]] ){
			parent[adj[node][i]] = node;
			dfs(adj[node][i]);
		}
}

void deviate(int node, int left)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m >> a >> b;
		ginp;
		dfs(b);
		int node = a;
		for(int i = 1 ;  ; i++){
			newname[i] = node;
			node = parent[node];
			if( node == 0 )
				break;
		}
	}
	return(0);
}