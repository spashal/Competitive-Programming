#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
ll mod = 1e9+7;
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
    ll tests = t;
	while( t-- ){
		ll k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector< int > power;
		// precalculate powers of k
		power.pb(1);
		for(int i = 1 ; i <= n / 2 ; i++)
			power.pb((power[power.size() - 1]*k)% mod);


		ll ans = 0;
		for(int i = 0 ; i <= (n-1)/2 ; i++){
			ans = (ans + ((s[i] - 'a') * power[(n - 2 * i - 1)/2]) % mod) % mod;
		}
		for(int i = (n+1)/2 ; i < n ; i++){
			if(s[i] > s[n-1-i]){
				ans = (ans + 1) % mod;
				break;
			}
			if(s[i] < s[n-i-1])
				break;
		}
		cout << "Case #" << tests-t << ": ";
		cout << ans << endl;
	}
	return(0);
}