#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
bool vis[200005];
vector< ll > adj[200005], a[2];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

void dfs(ll node, bool clr){
	vis[node] = true;
	a[clr].pb(node);
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( !vis[adj[node][i]] )
			dfs(adj[node][i], 1 - clr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++){
			vis[i] = false;
			adj[i].clear();
		}
	    ginp;
	    for(int i = 1 ; i <= n ; i++)
	    	if( !vis[i] )
	    		dfs(i, 0);
	    if( a[0].size() > a[1].size() )
	    	a[0] = a[1];
	    cout << (int)a[0].size() << endl;
	    for(int i = 0 ; i < a[0].size() ; i++)
	    	cout << a[0][i] << " ";
	    cout << endl;
	    a[0].clear();
	    a[1].clear();
	}
	return(0);
}