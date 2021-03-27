#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
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
vector< vector< vector< ll > > > dp(1001, vector< vector< ll > > (1001, vector< ll > (2, -1)));

ll fun(ll k, ll i, ll dir){
	// cout << k << " " << i << " " << dir << endl;
	if(dp[k][i][dir] != -1)
		return dp[k][i][dir];
	else{
		if(dir == 0)
			dp[k][i][dir] = (fun(k, i - 1, dir) + fun(k - 1, i, 1 - dir)) % mod;
		else
			dp[k][i][dir] = (fun(k, i + 1, dir) + fun(k - 1, i, 1 - dir)) % mod;
	}
	return dp[k][i][dir];
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll k;
		cin >> n >> k;
		for(int i = 0 ; i <= k ; i++)
			for(int j = 0 ; j < n ; j++){
				dp[i][j][0] = -1;
				dp[i][j][1] = -1;
			}
		for(int i = 0 ; i <= n ; i++){
			dp[1][i][0] = 1;
			dp[1][i][1] = 1;
		}
		for(int i = 1 ; i <= k ; i++){
			dp[i][0][0] = 1;
			dp[i][n][1] = 1;
		}

		for(int i = 2 ; i <= k ; i++){
			for(int j = n - 1 ; j >= 0 ; j--)
				dp[i][j][1] = (dp[i][j + 1][1] + dp[i - 1][j][0]) % mod;
			for(int j = 1 ; j <= n ; j++)
				dp[i][j][0] = (dp[i][j - 1][0] + dp[i - 1][j][1]) % mod;
		}

		cout << dp[k][0][1] << endl;
	}
	return(0);
}