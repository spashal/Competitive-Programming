#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a, base;
vector< pair<ll, ll> > End;
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

void Set(int val, int pos){
	int change = val - tree[pos];
    End[pos] = mp(pos - base + 1, pos - base + 1);
	tree[pos] = val;
	for(int node = pos / 2 ; node > 0 ; node /= 2){
        if( End[node].ss < pos - base + 1 )
            End[node].ss = pos - base + 1;
        if( End[node].ff == 0 )
            End[node].ff = pos - base + 1;
		tree[node] += change;
    }
}

ll sum(int node, int l, int r){
    if( End[node].ff == l and End[node].ss == r )
        return tree[node];
	ll ans = 0;
	ll mid = End[node * 2].ss;
    if( mid < l )
        ans += sum(node * 2 + 1, l, r);
    else if( mid >= r )
        ans += sum(node * 2, l, r);
    else{
        ans += sum(node * 2 + 1, mid + 1, r);
        ans += sum(node * 2, l, mid);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, l;
    cin >> n >> m;
    ll temp = n;
    base = 1;
    while( n >= 1 ){
    	n /= 2;
    	base *= 2;
    	ult++;
    }
    n = temp;
    tree.resize(2 * base, 0);
    End.resize(2 * base, mp(0, 0));
    for(int i = 0 ; i < n ; i++){
    	cin >> a;
    	Set(a, i + base);
    }
    for(int i = 0 ; i < m ; i++){
    	cin >> a >> l >> r;
    	if( a == 1 )
    		Set(r, l + base);
    	else
    		cout << sum(1, l + 1, r) << endl;
    }
	return(0);
}