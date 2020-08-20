#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], b[10005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < m ; i++ ) cin >> b[i];
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
    	cin >> n >> m;
    	ari;
    	bri;
    	ll ans = 0;
    	for(int i = 0 ; i < n ; i++){
    		for(int j = 0 ; j < m ; j++)
    			if( a[i] == b[j] ){
    				ans = a[i];
    				break;
    			}
    		if( ans > 0 )
    			break;
    	}
    	if( ans == 0 )
    		cout << "NO" << endl;
    	else
    		cout << "YES" << endl << "1 " << ans << endl;
    }

	return(0);
}