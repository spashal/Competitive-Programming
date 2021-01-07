#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
bool vis[200005];
vector< ll > adj[200005];
ll ans[200005], d[200005];
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

void fun(ll node){
	vis[node] = true;
	ans[node] = d[node];
	for(int i = 0 ; i < adj[node].size() ; i++){
		if( !vis[adj[node][i]] and d[adj[node][i]] > d[node] ){
			fun(adj[node][i]);
		}
		if( d[adj[node][i]] > d[node] )
			ans[node] = min(ans[adj[node][i]], ans[node]);
		else
			ans[node] = min(ans[node], d[adj[node][i]]);
	}
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++){
			d[i] = -1;
			vis[i] = false;
			adj[i].clear();
		}
		for(int i = 0 ; i < m ; i++){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
		}
		queue< ll > q;
		d[1] = 0;
		ans[1] = 0;
		q.push(1);
		while( !q.empty() ){
			ll node = q.front();
			q.pop();
			for(int i = 0 ; i < adj[node].size() ; i++)
				if( d[adj[node][i]] == -1 ){
					d[adj[node][i]] = d[node] + 1;
					// ans[adj[node][i]] = d[node] + 1;
					q.push(adj[node][i]);
				}
		}
		fun(1);
		for(int i = 1 ; i <= n ; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}