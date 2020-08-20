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
vector< ll > tree;
vector< pair<ll, ll> > End;

void Set(ll val, int pos){
	tree[pos] = val;
	End[pos].ff = pos - base + 1;
	End[pos].ss = pos - base + 1;
	for(int node = pos / 2 ; node > 0 ; node /= 2){
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		if( End[node].ss < pos - base + 1 )
			End[node].ss = pos - base + 1;
		if( End[node].ff == 0 )
			End[node].ff = pos - base + 1;
	}
}

ll minOverSeg(int node, int l, int r){
	if( l == End[node].ff and r == End[node].ss )
		return tree[node];
	if( r <= End[node * 2].ss )
		return minOverSeg(node * 2, l, r);
	else if( l > End[node * 2].ss )
		return minOverSeg(node * 2 + 1, l, r);
	else
		return min(minOverSeg(node * 2, l, End[node * 2].ss), minOverSeg(node * 2 + 1, End[node * 2 + 1].ff, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> q;
	int temp = n;
	base = 1;
	while( temp >= 1 ){
		base *= 2;
		temp /= 2;
	}
	tree.resize(2 * base, INT_MAX);
	End.resize(2 * base, mp(0, 0));
	for(int i = 0 ; i < n ; i++){
		cin >> a;
		Set(a, i + base);
	}
	for(int i = 0 ; i < q ; i++){
		cin >> a >> l >> r;
		if( a == 1 )
			Set(r, l + base);
		else
			cout << minOverSeg(1, l + 1, r) << endl;
	}
	return(0);
}