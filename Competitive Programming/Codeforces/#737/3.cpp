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
ll mod = 1e9+7;


ll po(ll k){
	ll temp = 0, ans = 1;
	ll num = 2;
	while(k){
		if(k%2)
			ans = (ans*num)%mod;
		num = (num*num)%mod;
		k /= 2;
	}
	return ans%mod;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll k;
		cin >> n >> k;
		vector<ll> dp(k+1, 0);
		dp[0] = 1;
		for(ll i = 1 ; i <= k ; i++){
			if(n%2){
				dp[i] = (((po(n-1) + 1)%mod)*dp[i-1])%mod;
			}
			else 	
				dp[i] = ((((po(n-1)-1+mod)%mod)*dp[i-1])%mod + po(((i-1)*n)))%mod;
		}
		cout << dp[k]%mod << endl;
	}	return(0);
}