#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005], val(100005, 0);
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

map< pair<ll, ll>, ll> Map;	

int dfs(int node, int parent){
	ll edge = Map[mp(node, parent)];
	Map[mp(node, node)] = edge;
	val[edge] = 0;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if( adj[node][i] != parent )
			val[edge] += dfs(adj[node][i], node);
	}
	val[edge]++;
	return val[edge];
} // definition of dfs funtion(recursive)	

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod = 1e9 + 7;
    cin >> t;

	while( t-- ){
		cin >> n;
		ll k = 0;
		vector< pair<ll, ll> > ar; // variable definitions

		for(int i = 1 ; i < n ; i++){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
			Map[mp(u, v)] = i;
			Map[mp(v, u)] = i;
		} // scanning graph

		cin >> m;
		vector< ll > p(m, 0);
		for(int i = 0 ; i < m ; i++)
			cin >> p[i];
		sort(p.begin(), p.end(), greater< ll > ()); // scanning prime factors
		
		if( m > n - 1 ){
			for(int i = 1 ; i < m - n + 1 ; i++)
				p[0] = (p[0] * p[i]) % mod;
			vector< ll > temp;
			temp.pb(p[0]);
			for(int i = m - n + 1 ; i < m ; i++)
				temp.pb(p[i]);
			p.clear();
			p = temp;
		} // handling case for m > n - 1
		
		dfs(1, 0);
		ll ans = 0;
		for(int i = 1 ; i <= n ; i++)
			if( Map[mp(i, i)] > 0 )
				ar.pb(mp((n - val[Map[mp(i, i)]]) * val[Map[mp(i, i)]], Map[mp(i, i)]));
		sort(ar.begin(), ar.end(), greater< pair<ll, ll> > ());
		
		for(int i = 0 ; i < ar.size() ; i++){
			if( k < m ){
				ans = (ans + (ar[i].ff * p[k]) % mod) % mod;
				k++;
			}
			else
				ans = (ans + ar[i].ff) % mod;
		}
		cout << ans << endl; // main algorithm
		
		for(int i = 1 ; i <= n ; i++){
			val[i] = 0;
			for(int j = 0 ; j < adj[i].size() ; j++)
				Map[mp(i, adj[i][j])] = 0;
			Map[mp(i, i)] = 0;
			adj[i].clear();
		} // resetting all the vectors and maps

	}
	return(0);
}