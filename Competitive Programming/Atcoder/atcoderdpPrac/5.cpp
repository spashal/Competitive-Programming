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
	ll W;
	cin >> n >> W;
	vector< pair<ll, ll> > inp(n, mp(-1, -1));
	for(int i = 0 ; i < n ; i++)
		cin >> inp[i].ff >> inp[i].ss;
	vector< ll > dp(1e5+1, INT_MAX);
	dp[0] = 0;
	for(int i = 0 ; i < n ; i++)
		for(int cost = 1e5 - inp[i].ss ; cost >= 0 ; cost--)
			dp[cost+inp[i].ss] = min(dp[cost+inp[i].ss], dp[cost] + inp[i].ff);
	ll ans = 0;
	for(int i = 0 ; i <= 1e5 ; i++)
		if(dp[i] <= W)
			ans = i;
	cout << ans << endl;
	return(0);
}