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
    ll x, y;
    cin >> t;
	while( t-- ){
		cin >> n >> m >> x >> y;
		if( ceil((ld)y / 2) > x )
			cout << n * m * x << endl;
		else{
			if( (n * m) % 2 == 0 )
				cout << (n * m * y) / 2 << endl;
			else if( y <= x )
				cout << y * (n * m + 1) / 2 << endl;
			else
				cout<< (y * m * n) / 2 + (n * m + 1) / 2 << endl;
		}
	}
	return(0);
}