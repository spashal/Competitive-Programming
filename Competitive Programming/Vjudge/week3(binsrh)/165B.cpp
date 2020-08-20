#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, k, t, a[100005];
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

ll val(ll v, ll k){
	ll ans = v, blah = k;
	while( (v / blah) ){
		ans += v / blah;
		blah *= k;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> k;
	ll low = 2, high = 10000000000;
	while( low <= high ){
		ll mid = low + (high - low) / 2;
		// cout << mid << endl;
		if( val(mid, k) < n )
			low = mid + 1;
		else
			high = mid - 1;
	}
	if( val(high, k) < n )
		cout << high + 1 << endl;
	else
		cout << high << endl;
	return(0);
}