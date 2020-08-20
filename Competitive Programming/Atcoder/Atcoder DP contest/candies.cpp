#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, k, a[105];
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
const ll mod = 1e9 + 7;

void add(ll& a, ll b){
	a += b;
	if( a >= mod )
		a -= mod;
	if( a < 0 )
		a += mod;
}

void sub(ll&a , ll b){
	a -= b;
	if( a >= mod )
		a -= mod;
	if( a < 0 )
		a += mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ari;
    vector< ll > dp(k + 1, 0);
    ll maxi = 0;
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++){
    	vector< ll > temp(k + 1, 0);
		for(int j = k ; j >= 0 ; j--){
			if( j + 1 <= j + min(a[i], k - j) ){
				add(temp[j + 1], dp[j]);
				if( a[i] + 1 <= k - j )
					sub(temp[j + min(a[i], k - j) + 1], dp[j]);
			}
		}
		ll prefix_sum = 0;
		for(int j = 0 ; j <= k ; j++){
			add(prefix_sum, temp[j]);
			add(dp[j], prefix_sum);
		}
    }
	cout << dp[k] << endl;
	return(0);
}