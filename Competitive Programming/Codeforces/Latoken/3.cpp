#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[400005], b[400005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < n ; i++ ) cin >> b[i];
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
vector< bool > vis;
vector< int > indexx;
ll mod = 1e9+7;

ll dfs(int node){
	// cout << "*" << node << endl;
	vis[node] = true;
	if(vis[indexx[b[node]]])
		return 0;
	dfs(indexx[b[node]]);
	return 2;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		indexx.resize(n+1, 0);
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
			indexx[a[i]] = i;
		}
		for(int i = 1 ; i <= n ; i++)
			cin >> b[i];
		vis.resize(n+1, false);
		ll ans = 1;
		for(int i = 1 ; i <= n ; i++)
			if(!vis[i]){
				ll temp = dfs(i);
				// cout << temp << " *& " << endl;
				ans = (ans*temp)%mod;
			}
		cout << ans << endl;
		indexx.clear();
		vis.clear();
	}
	return(0);
}