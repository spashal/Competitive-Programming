#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, k, Q, base, a[500005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
vector< pair<ll, ll> > End;
vector< ll > tree;

void printar(vector< ll > ar, int start, int stop){
	for(int i = start ; i < stop ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

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
    cin >> n;
    ari;
    cin >> Q;
    ll temp = 1e6 + 1;
    base = 1;
    while( temp >= 1 ){
    	temp /= 2;
    	base *= 2;
    }
    tree.resize(2 * base, 0);
    End.resize(2 * base, mp(0, 0));

    vector< pair< pair<ll, ll>, ll> > queries;
    for(int i = 0 ; i < 1e6 + 1 ; i++)
    	Set(0, i + base);
    
    ll r, l;
    for(int i = 0 ; i < Q ; i++){
    	cin >> l >> r;
    	queries.pb(mp(mp(r, l), i));
    }
    
    vector< ll > lastPos(n + 1, -1), q(Q + 1, 0);
    sort(queries.begin(), queries.end());
    k = 0;
    for(int i = 0 ; i < n ; i++){
    	if( lastPos[a[i]] != -1 )
    		Set(0, lastPos[a[i]] + base);
    	lastPos[a[i]] = i;
    	Set(1, i + base);
    	while( k < queries.size() and queries[k].ff.ff == i + 1 ){
    		q[queries[k].ss] = sum(1, queries[k].ff.ss, queries[k].ff.ff);
    		k++;
    	}
    }
    for(int i = 0 ; i < Q ; i++)
    	cout << q[i] << endl;
	return(0);
}