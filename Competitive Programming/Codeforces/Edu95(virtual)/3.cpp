#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
bool a[200005];
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
		// for(int i = 0 ; i < n ; i++)
		// 	cout << a[i] << " ";
		// cout << endl;
		vector< ll > me(n + 1, 0), frnd(n + 1, 0);
		for(int i = n - 1 ; i >= 0 ; i--){
			if( i + 1 < n ){
				frnd[i] = me[i + 1] + a[i + 1];
				me[i] = frnd[i + 1];
				// cout << frnd[i] << " " << me[i] << endl;
			}
			if( i + 2 < n ){
				frnd[i] = min(me[i + 2] + a[i + 2] + a[i + 1], frnd[i]);
				me[i] = min(frnd[i + 2], me[i]);
				// cout << frnd[i] << " " << me[i] << endl << endl;
			}
		}
		ll ans = me[0] + a[0];
		if( n > 1 )
			ans = min(ans, me[1] + a[0] + a[1]);
		cout << ans << endl;
		for(int i = 0 ; i < n ; i++)
			a[i] = false;
	}
	return(0);
}