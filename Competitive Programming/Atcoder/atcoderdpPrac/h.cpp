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
    cin >> n >> m;
    ll mod = 1e9+7;
    vector< string > grid(n, "");
    for(int i = 0 ; i < n ; i++)
    	cin >> grid[i];
    vector< vector< ll > > dp(n, vector< ll > (m, 0));
    for(int i = n-1; i >= 0 ; i--)
    	if(grid[i][m-1] == '.')
    		dp[i][m-1] = 1;
    	else
    		break;
    for(int i = m-1 ; i >= 0 ; i--)
    	if(grid[n-1][i] == '.')
    		dp[n-1][i] = 1;
    	else
    		break;
    for(int i = m - 2 ; i >= 0 ; i--)
    	for(int j = n - 2 ; j >= 0 ; j--){
    		if(grid[j+1][i] == '.')
    			dp[j][i] = (dp[j][i] + dp[j+1][i]) % mod;
    		if(grid[j][i+1] == '.')
    			dp[j][i] = (dp[j][i] + dp[j][i+1]) % mod;
    	}
    cout << dp[0][0] << endl;
	return(0);
}