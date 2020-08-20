#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, S, yet, w[100005];
vector< pair<ll, ll> > adj[100005];
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
vector< ll > leaves;
priority_queue< pair<ll, ll> > pq;

ll dfs(ll node, ll parent){
	ll ctr = 0;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i].ff != parent ){
			ctr++;
			leaves[node] += dfs(adj[node][i].ff, node);
		}
	if( ctr == 0 )
		leaves[node] = 1;
	return leaves[node];
}

void set_dfs(ll node, ll parent, ll wt){
	// cout << node << " " << parent << endl;
	for(int i = 0 ; i <  adj[node].size() ; i++)
		if( adj[node][i].ff != parent )
			set_dfs(adj[node][i].ff, node, adj[node][i].ss);
	ll temp = wt * leaves[node];
	w[node] = wt;
	yet += temp;
	pq.push(mp(leaves[node] * (w[node] - w[node] / 2), node));
}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> S;
		leaves.resize(n + 1, 0);
		for(int i = 1 ; i <= n ; i++)
			adj[i].clear();
		yet = 0;
		ll moves = 0;
		for(int i = 0 ; i < n - 1 ; i++){
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		dfs(1, 0);
		set_dfs(1, 0, 0);
		while( yet > S ){
			yet -= pq.top().ff;
			w[pq.top().ss] /= 2;
			ll node = pq.top().ss;
			moves++;
			pq.push(mp(leaves[node] * (w[node] - w[node] / 2), node));
			pq.pop();
		}
		leaves.clear();
		while( !pq.empty() )
			pq.pop();
		cout << moves << endl;
	}
	return(0);
}