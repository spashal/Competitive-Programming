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
	
void solve(){
	ll k;
	cin >> n >> k;
	vector< ll > h(n, 0);
	for(int i = 0 ; i < n ; i++)
		cin >> h[i];
	ll up = 0, down = 0;
	up = down = h[0];
	for(int i = 1 ; i < n ; i++){
		if( up + k - 1 >= h[i] and down - k + 1 <= h[i] + k - 1 ){
			up = min(h[i] + k - 1 , up + k - 1);
			down = max(h[i], down - k + 1);
		}
		else{
			cout << "no\n";
			return;
		}
	}
	if( down > h[n - 1] or up < h[n - 1] )
		cout << "no\n";
	else
		cout << "yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- )
		solve();
	return(0);
}