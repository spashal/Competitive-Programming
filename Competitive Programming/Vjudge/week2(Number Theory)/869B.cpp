#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

int main(){
	ll a, b;
	cin >> a >> b;
	if( a > b or (b - 5) >= a )
		cout << "0" << endl;
	else{
		ll ans = 1;
		for(ll i = a + 1 ; i <= b ; i++){
			ans *= (i % 10);
			ans %= 10; 
		}
		cout << ans << endl;
	}
	return(0);
}