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
	cin >> n;
	vector< ld > p(n, 0.0);
	for(int i = 0 ; i < n ; i++)
		cin >> p[i];
	vector< ld > dp(n + 1, 0.0);
	dp[0] = (1.0-p[0]);
	dp[1] = p[0];
	for(int i = 1 ; i < n ; i++){
		for(int j = i+1 ; j > 0 ; j--)
			dp[j] = dp[j]*(1.0 - p[i]) + dp[j-1] * p[i];
		dp[0] *= (1.0 - p[i]);
	}
	ld ans = 0.0;
	for(int i = (n+1)/2 ; i <= n ; i++)
		ans += dp[i];
	cout << setprecision(10) << ans << endl;
	return(0);
}