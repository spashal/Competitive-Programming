#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, p[100005], h[100005], allchildren[100005], flag[100005];
vector< ll > adj[100005];
#define pri for( int i = 1 ; i <= n ; i++ ) cin >> p[i];
#define hri for( int i = 1 ; i <= n ; i++ ) cin >> h[i];
#define ginp for( int i = 0 ; i < n - 1 ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair

ll dfs_build(int node, int parent){
	allchildren[node] = 0;
	flag[node] = false;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i] != parent )
			allchildren[node] += dfs_build(adj[node][i], node);
	allchildren[node] += p[node];
	return allchildren[node];
}

void dfs_check(int node, int parent){
	if( h[node] < allchildren[node] * -1 )
		flag[node] = true;
	if( h[node] > allchildren[node] )
		flag[node] = true;
	ll maxhappy = h[node] + p[node], checker = 0;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i] != parent ){
			checker += h[adj[node][i]];
			dfs_check(adj[node][i], node);
		}
	if( maxhappy < checker or llabs(maxhappy - checker) % 2 )
		flag[node] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		bool finalflag = false;
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++)
			adj[i].clear();	
		pri;
		hri;
		ginp;
		dfs_build(1, 0);
		dfs_check(1, 0);
		for(int i = 1 ; i <= n ; i++){
			if( flag[i] )
				finalflag = true;
		}
		if( finalflag )
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return(0);
}