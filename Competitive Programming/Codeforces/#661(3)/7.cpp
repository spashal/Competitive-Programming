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
		cin >> n;
		vector< ll > dp(n, 0), ctr(n, 0);
		ll ans = 0;
		vector< pair<ll, ll> > ar;
		for(int i = 0 ; i < n ; i++){
			ll a, b;
			cin >> a >> b;
			ar.pb(mp(a, b));
		}
		sort(ar.begin(), ar.end());
		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = i + 1 ; j < n ; j++)
				if( (ar[i].ff <= ar[j].ff and ar[i].ss >= ar[j].ss) or (ar[i].ff == ar[j].ff and ar[i].ss <= ar[j].ss) )
					ctr[i] = max(ctr[i], ctr[j]);
			ctr[i]++;
		}
		for(int i = 0 ; i < n ; i++)
			cout << ar[i].ff << " " << ar[i].ss << " " << ctr[i] << endl;
		cout << endl;
		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = i + 1 ; j < n ; j++)
				if( ar[i].ss < ar[j].ff )
					dp[i] = max(dp[i], dp[j]);
			dp[i] += ctr[i];
			ans = max(dp[i], ans);
		}
		cout << ans << endl;
	}
	return(0);
}