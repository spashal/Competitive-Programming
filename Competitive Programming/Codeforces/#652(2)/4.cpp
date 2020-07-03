#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, mod = 1000000007;
ll dp[2000006][2];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	for(int i = 3 ; i <= 2000000 ; i++){
		dp[i][1] = (2 * dp[i - 2][0] + dp[i - 1][0] + 4) % mod;
		dp[i][0] = (2 * max(dp[i - 2][1], dp[i - 2][0]) + max(dp[i - 1][0], dp[i - 1][1])) % mod;
	}
	cin >> t;
	while( t-- ){
		cin >> n;
		cout << max(dp[n][0], dp[n][1]) << endl;
	}
	return(0);
}