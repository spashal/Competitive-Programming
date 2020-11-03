#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
bool root[100005];
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

ll dfs(ll node, ll parent, ll sum){
	sum += a[node];
	for(int i = 0 ; i < adj[node].size() ; i++){
		if( adj[node][i] != parent)
			dfs(adj[node][i], node, sum);
	}
	ma[node] = sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		root[i] = true;
	for(int i = 2 ; i <= n ; i++){
		cin >> m;
		adj[m].pb(i);
		root[m] = false;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> m;
		a[i] = m;
	}
	dfs(1, 0, 0);
	return(0);
}