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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll x;
		cin >> n >> x;
		vector< ll > aa;
		for(int i = 0 ; i < n ; i++){
			ll aka;
			cin >> aka;
			aa.pb(aka);
		}
		ll ans = 0;
		vector< ll > cnt(n, 1);
		for(int i = 0 ; i < aa.size() ; i++){
			// ans += aa[i] * cnt[i];
			if( aa[i] % x == 0 ){
				aa.pb(aa[i]/x);
				cnt.pb(x*cnt[i]);
			}
			else
				break;
			// cout << ans << " " << aa[i]/x << " " << x * cnt[i] << endl;
		}
		for(int i = 0 ; i < aa.size() ; i++)
			ans += aa[i] * cnt[i];
		cout << ans << endl;
	}
	return(0);
}