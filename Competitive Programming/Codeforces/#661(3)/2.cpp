#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[105], b[105];
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
		cin >> n;
		ll mini1 = INT_MAX;
		ll mini2 = mini1, ans = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			if( mini1 > a[i] )
				mini1 = a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin >> b[i];
			if( mini2 > b[i] )
				mini2 = b[i];
		}
		for(int i = 0 ; i < n ; i++){
			ans += max(a[i] - mini1, b[i] - mini2);
		}
		cout << ans << endl;
	}
	return(0);
}