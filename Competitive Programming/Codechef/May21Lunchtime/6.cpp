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
ll inf = -1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll k;
		cin >> n >> k;
		ari;
		// so the transitions are:- continue the subarray, or make a new one
		// please note that dp[i][j] means considering first j elements and jth one should be included
		// hence the need to take maximum of all dp[k][i] at the end for the final answer
		vector< vector< ll > > dp(k+1, vector< ll > (n, inf));
		vector< vector<ll> > prefix(k+1, vector< ll > (n, inf));
		dp[1][0] = a[0];
		for(int i = 0 ; i < n ; i++){
			prefix[0][i] = 0;
			dp[0][i] = 0;
		}
		prefix[1][0] = dp[1][0];
		ll maxPrev = inf;
		for(int i = 1 ; i <= k ; i++){
			for(int j = 1 ; j < n ; j++){
					dp[i][j] = max((ll)inf, max(dp[i][j-1] + (ll)i*a[j], prefix[i-1][j-1] + (ll)i*a[j]));
					prefix[i][j] = max(prefix[i][j-1], dp[i][j]);
			}
		}
		ll ans = inf;
		for(int i = 0 ; i < n ; i++)
			ans = max(ans, dp[k][i]);
		cout << ans << endl;
	}
	return(0);
}