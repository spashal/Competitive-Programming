// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
		cin >> n;
		ari;
		vector< ll > dp(n, 0);
		// for(int i = 0 ; i < n ; i++)
			// a[i]
		ll ans = 0;
		for(int i = n - 1 ; i >= 0 ; i--){
			if( i + a[i] < n )
				dp[i] = dp[i + a[i]] + a[i];
			else
				dp[i] = a[i];
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return(0);
}