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
	
ll fun(vector< set< ll > > &st, ll cur){
	// cout << cur << " & ";
	ll ans = 0;
	ll last = *st[cur].begin();
	for(int i = cur + 1 ; i < last ; i++){
		for(set< ll > :: iterator it = st[i].begin() ; it != st[i].end() ; it++){
			set< ll > :: iterator itr = st[cur].upper_bound(*it);
			// cout << *it << " ** " << *itr << " * ";
			// if( itr == st[cur].end() ){
				// continue;
			// }
			ans += distance(st[cur].begin(), itr);
			// cout << ans << " ";
		}
	}
	return ans;
}

ll nancy4(ll kx){
 return (kx * (kx - 1) * (kx - 2) * (kx - 3)) / 24;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ll ans = 0;
		vector< set< ll > > followers(n + 1);
		vector< ll > present(n + 1, -1), others(n + 1, 0);
		ari;
		for(int i = n - 1 ; i >= 0 ; i--)
			if( present[a[i]] > -1 ){
				followers[i] = followers[present[a[i]]];
				followers[i].insert(present[a[i]]);
				present[a[i]] = i;
			}
			else
				present[a[i]] = i;
		vector< ll > dp(n + 1, 0);
		for(int i = n - 1 ; i >= 0 ; i--)
			if( !followers[i].empty() ){
				dp[i] += dp[*followers[i].begin()];
				if( i < n - 3 )
					dp[i] += fun(followers, i);
				if( followers[i].size() >= 3 )
					others[i] = nancy4(followers[i].size() + 1);
			}
		// printar(dp, 0, n);
		for(int i = 1 ; i <= n ; i++){
			if( present[i] >= 0 )
				ans += others[present[i]];
			ans += dp[i - 1];
		}
		cout << ans << endl;
	}
	return(0);
}