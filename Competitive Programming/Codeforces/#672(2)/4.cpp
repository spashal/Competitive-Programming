#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a, l, q, r, base;
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
vector< vector< vector< ll > > > tree(1048578, vector< vector<ll> > (2, vector< ll > (2, 0)));
vector< pair<ll, ll> > End(1048578, mp(0, 0));

void fun(int node1, int node2, int node3){
	tree[node1][0][0] = max(tree[node2][0][0], tree[node2][0][0] + tree[node3][1][0]);
	tree[node1][0][0] = max(tree[node1][0][0], max(tree[node3][0][0], tree[node2][0][1] + tree[node3][0][0]));

	tree[node1][0][1] = max(tree[node2][0][1], tree[node3][0][1]);
	tree[node1][0][1] = max(tree[node1][0][1], max(tree[node2][0][1] + tree[node3][0][1], tree[node2][0][0] + tree[node3][1][1]));

	tree[node1][1][0] = max(tree[node2][1][0], tree[node3][1][0]);
	tree[node1][1][0] = max(tree[node1][1][0], max(tree[node2][1][1] + tree[node3][0][0], tree[node2][1][0] + tree[node3][1][0]));

	tree[node1][1][1] = max(tree[node2][1][1], tree[node3][1][1]);
	tree[node1][1][1] = max(tree[node1][1][1], max(tree[node2][1][1] + tree[node3][0][1], tree[node2][1][0] + tree[node3][1][1]));		
}

void Set(ll val, int pos, bool flag){
	tree[pos][0][0] = val;
	tree[pos][1][1] = -1 * val;
	End[pos].ff = pos - base + 1;
	End[pos].ss = pos - base + 1;
	for(int node = pos / 2 ; node > 0 ; node /= 2){
		fun(node, node * 2, node * 2 + 1);
		if( flag ){if( End[node].ss < pos - base + 1 )
					End[node].ss = pos - base + 1;
				if( End[node].ff == 0 )
					End[node].ff = pos - base + 1;}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> q;
		int temp = n;
		base = 1;
		while( temp >= 1 ){
			base *= 2;
			temp /= 2;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> a;
			Set(a, i + base, 1);
		}
		cout << tree[1][0][0] << "\n";
		for(int i = 0 ; i < q ; i++){
			cin >> l >> r;
			ll n1 = tree[base + l - 1][0][0];
			ll n2 = tree[base + r - 1][0][0];
			Set(n1, base + r - 1, 0);
			Set(n2, base + l - 1, 0);
			cout << tree[1][0][0] << "\n";
		}
		for(int i = 0 ; i <= n + base ; i++){
			tree[i][0][0] = 0;
			tree[i][0][1] = 0;
			tree[i][1][0] = 0;
			tree[i][1][1] = 0;
			End[i] = mp(0, 0);
		}
	}
	return(0);
}