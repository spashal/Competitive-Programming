#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll a, b, x, y;
		cin >> x >> y >> a >> b;
		if( x * y < 0 or b >= 2 * a )
			cout << a * (llabs(x) + llabs(y)) << endl;
		else
			cout << b * min(llabs(x), llabs(y)) + a * (max(llabs(x), llabs(y)) - min(llabs(x), llabs(y)))<< endl;
	}
	return(0);
}