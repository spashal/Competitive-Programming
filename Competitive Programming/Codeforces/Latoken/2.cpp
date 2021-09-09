#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[400005];
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
		// handle n = 1 
		ari;
		if(n == 1){
			cout << a[0] << "\n";
			continue;
		}
		ll ans = 0;
		for(int i = 1 ; i < n-1 ; i++){
			if(a[i-1] < a[i] and a[i] > a[i+1]){
				ans += a[i] - max(a[i-1], a[i+1]);
				a[i] = max(a[i-1], a[i+1]);
			}
		}
		// cout << ans << " * ";
		if(a[0] > a[1]){
			ans += a[0]-a[1];
			a[0] = a[1];
		}
		if(a[n-1] > a[n-2]){
			ans += a[n-1]-a[n-2];
			a[n-1] = a[n-2];
		}
		ans += llabs(a[0]);
		ans += llabs(a[n-1]);
		for(int i = 0 ; i < n-1 ; i++)
			ans += llabs(a[i] - a[i+1]);
		cout << ans << endl;
	}
	return(0);
}