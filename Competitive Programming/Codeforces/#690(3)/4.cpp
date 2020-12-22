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

ll fun(int i, ll sum, ll ctr){
	// cout << i << " ";
	if( i >= n )
		return (ctr - 1);
	if( i == n - 1 and a[i] == sum )
		return ctr;
	ll suma = 0;
	for(int j = i ; j < n ; j++){
		suma += a[j];
		if( suma == sum ){
			return fun(j + 1, sum, ctr + 1);
		}
	}
	return -1;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		ll ans = 1;
		for(int i = 0 ; i < n - 1 ; i++){
			ll sum = 0;
			for(int j = 0 ; j <= i ; j++){
				sum += a[j];
			}
			// cout << i << " " << sum << endl;
			if( i < n - 1)
			ans = max(ans, fun(i + 1, sum, 2));
			// cout << ans << " " << sum << " * " << endl;
		}
		cout << n - ans << endl;
	}
	return(0);
}