#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[5005], b[5005], c[5005];
vector< ll > adj[100005];
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
	cin >> n >> m >> k;
	ari;
	ginp;
	for(int i = 0 ; i < n ; i++){
		xs[i] = k - a[i];
	}
	return(0);
}