#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
bool vis[50];
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

void prep(){
	for(int i = 0 ; i < 'z' - 'a' ; i++)
		vis[i] = false;
}

void dfs(int node){
	vis[node] = true;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( !vis[adj[node][i]] )
			dfs(adj[node][i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		string a, b;
		bool flag = false;
		set< pair< ll, ll> > trans;
		cin >> a >> b;
		for(int i = 0 ; i < 26 ; i++)
			adj[i].clear();
		for(int i = 0 ; i < n ; i++){
			trans.insert(mp(-1 * a[i], i));
		}
		set< pair< ll, ll> > :: iterator itr;
		for( itr = trans.begin() ; itr != trans.end() ; itr++){
			prep();
			dfs(a[itr -> ss] - 'a');
			if( !vis[b[itr -> ss] - 'a'] ){
				if( b[itr -> ss] < a[(itr -> ss)] )
					flag = true;
				adj[a[itr -> ss] - 'a'].pb(b[itr -> ss] - 'a');
				adj[b[itr -> ss] - 'a'].pb(a[itr -> ss] - 'a');
			}
		}
		if( flag )
			cout << "-1" << endl;
		else{
			int ans = 0;
			for(int i = 0 ; i < 26 ; i++)
				ans += adj[i].size();
			cout << ans / 2 << endl;
		}
	}
	return(0);
}