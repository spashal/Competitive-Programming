#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], ctr = 0, val[200005];
bool vis[200005];
vector< ll > adj[200005];
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

void dfs(ll node){
	vis[node] = true;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( !vis[adj[node][i]] ){
			val[ctr]++;
			dfs(adj[node][i]);
		}
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map< pair<ll, ll>, bool > edge;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
    	ll u, v;
    	cin >> u >> v;
    	if( edge[mp(u, v)] )
    		continue;
    	edge[mp(u, v)] = true;
    	edge[mp(v, u)] = true;
    	adj[v].pb(u);
    	adj[u].pb(v);
    }
    for(int i = 1 ; i <= n ; i++)
    	if( !vis[i] ){
    		dfs(i);
    		val[ctr]++;
    		ctr++;
    	}
    ll ans = 0;
    for(int i = 0 ; i < ctr ; i++)
    	ans = max(val[i], ans);
    cout << ans << endl;
	return(0);
}