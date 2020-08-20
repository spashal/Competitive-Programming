#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[5005], b[5005], c[5005], bnbr[5005];  //bnbr = best neighbour 
vector< ll > adj[100005];
bool inc[5005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i] >> b[i] >> c[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int main(){
	vector< pair< ll, ll> ar;
	cin >> n >> m >> k;
	ari;
	ginp;
	for(int i = 0 ; i < n ; i++){
		xs[i] = k - a[i];
		k += b[i];

		ar.push_back(make_pair(c[i], i));
		bnbr[i] = c[i];
		for(int j = 0 ; j < adj[i].size() ; j++)
			bnbr[i] = max(bnbr[i], c[adj[i][j]]); 
	}
	sort(ar.begin(), ar.end());
	for(int i = n - 2 ; i >= 0 ; i--)
		xs[i] = min(xs[i - 1], xs[i]);
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		if( xs[ar[i].ss] ){
			ans += c[ar[i].ff];
			bnbr[ar[i].ss] = 5005;
			for(int j = 0 ; j < adj[ar[i].ss].size() ; j++)
				if( !inc[adj[ar[i].ss][j]] )
					bnbr[ar[i].ss] = max(bnbr[ar[i].ss], c[adj[ar[i].ss][j]]);
			if( bnbr[ar[i].ss] == 5005 )
				bnbr[ar[i].ss] = -1;
			xs[ar[i].ss]--;
			inc[ar[i].ss] = true;
		}
		else{
			ll mini = -1;
			for(int j = 0 ; j < adj[ar[i].ss].size() ; j++){
				if( xs[adj[ar[i].ss][j]] and bnbr[adj[ar[i].ss][j]] == c[ar[i].ss] )
		}
			inc[ar[i].ss] = true;
		}
	}
	
	return(0);
}