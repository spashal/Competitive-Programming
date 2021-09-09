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
    vector< vector< ll > > dp(n+1, vector< ll > (3, INT_MIN)), inp(n, vector<ll> (3, 0));
    for(int i = 0 ; i < n ; i++)
    	cin >> inp[i][0] >> inp[i][1] >> inp[i][2];
    dp[n][0] = dp[n][1] = dp[n][2] = 0;
    for(int i = n-1 ; i >= 0 ; i--)
    	for(int j = 0 ; j < 3 ; j++)
    		 for(int k = 0 ; k < 3 ; k++)
    		 	if(j != k)
	    		 	dp[i][j] = max(dp[i][j], dp[i+1][k] + inp[i][j]);
    	
    cout << max(dp[0][1], max(dp[0][0], dp[0][2])) << endl;
	return(0);
}