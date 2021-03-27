#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, par[100005];
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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

ll root(ll node){
	while( par[node] != node )
		node = par[node];
	return node;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll k, ans = 0, e = 0;
		vector< pair< ll, pair< ll, ll> > > edges;
		cin >> n >> m >> k;
		for(int i = 1 ; i <= n ; i++)
			par[i] = i;
		for(int i = 0 ; i < m ; i++){
			ll a, b, limit;
			cin >> a >> b >> limit;
			edges.pb(mp(limit, mp(a, b)));
		}
		sort(edges.begin(), edges.end());
		ll the_one = -1;
		for(int i = 0 ; i < m ; i++)
			if( edges[i].ff >= k ){
				the_one = i;
				break;
			}
		if( the_one == -1 ){
			ll maxa = -1;
			the_one = m;
			while( e < n - 1 and the_one > -1 ){
				the_one--;
				if( root(edges[the_one].sf) != root(edges[the_one].sss) ){
					par[root(edges[the_one].sss)] = root(edges[the_one].sf);
					if( maxa < edges[the_one].ff ){
						ans = k - edges[the_one].ff;
						maxa = edges[the_one].ff;
					}
					else if( maxa == edges[the_one].ff )
						ans += k - maxa;
					e++;
				}
			}
			cout << ans << endl;
		}
		else{
			if( root(edges[the_one].sf) != root(edges[the_one].sss) ){
				par[root(edges[the_one].sss)] = root(edges[the_one].sf);
				if( edges[the_one].ff >= k )
					ans += (edges[the_one].ff - k);
				e++;
			}
			for(int i = 0 ; i < the_one ; i++)
				if( root(edges[i].sf) != root(edges[i].sss) ){
					par[root(edges[i].sss)] = root(edges[i].sf);
					e++;
				}
			if( e < n - 1 )
				while( e < n - 1 and the_one < m - 1 ){
					the_one++;
					if( root(edges[the_one].sf) != root(edges[the_one].sss) ){
						par[root(edges[the_one].sss)] = root(edges[the_one].sf);
						if( edges[the_one].ff >= k )
							ans += (edges[the_one].ff - k);
						e++;
					}
				}
			cout << ans << endl;
		}
	}
	return(0);
}