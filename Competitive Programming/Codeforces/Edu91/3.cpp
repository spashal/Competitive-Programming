#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], x;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> x;
		ari;
		sort(a, a + n, greater< ll > ());
		ll i = 0, ans = 0, yeti = 0;
		while( i < n ){
			if( (yeti + 1) * a[i] >= x ){
				ans++;
				i++;
				yeti = 0;
			}
			else{
				yeti++;
				i++;
			}
		}
		cout << ans << endl;
	}
	return(0);
}