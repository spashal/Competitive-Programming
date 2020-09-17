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
vector< vector< pair<ll, ll> > > child;
ll hala = 0;
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

ll dfs(ll node, ll parent){
	// cout << node << " " << parent<< endl;
	ll temp = 0;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i] != parent ){
			child[node].pb(mp(dfs(adj[node][i], node), adj[node][i]));
			temp += child[node].back().ff;
		}
	child[node].pb(mp(n - 1 - temp, parent));
	sort(child[node].begin(), child[node].end(), greater< pair<ll, ll> > ());
	return temp + 1;
}

void dfsn(ll node, ll parent){
	ll ctr = 0;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i] != parent ){
			dfsn(adj[node][i], node);
			ctr++;
		}
	if( ctr == 0 )
		hala = node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		hala = 0;
		cin >> n;
		child.resize(n + 1);
		ginp;
		dfs(1, 0);
		vector< pair<ll, ll> > ar;
		for(int i = 1 ; i <= n ; i++)
			ar.pb(mp(child[i][0].ff, i));
		sort(ar.begin(), ar.end());
		if( ar[0].ff == ar[1].ff ){
			dfsn(child[ar[1].ss][1].ss, ar[1].ss);
			cout << hala << " " << adj[hala][0] << endl;
			cout << hala << " " << ar[0].ss << endl;
		}

		else{
			cout << "1 " << adj[1][0] << endl;
			cout << "1 " << adj[1][0] << endl;
		}
		// for(int i = 0 ; i < n ; i++)
		// 	cout << ar[i].ff << "*" << ar[i].ss << " ";
		for(int i = 1 ; i <= n ; i++){
			child[i].clear();
			adj[i].clear();
		}
	}
	return(0);
}