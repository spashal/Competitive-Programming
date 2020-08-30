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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll temp;
		ll x1, x2, y1, y2, z1, z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		ll ans = min(z1, y2) * 2;
		temp = min(z1, y2);
		y2 -= min(z1, y2);
		z1 -= temp;
		temp = min(y1, x2);
		y1 -= temp;
		x2 -= temp;
		temp = min(x1, z2);
		z2 -= temp;
		x1 -= temp;
		temp = min(y1, y2);
		y1 -= temp;
		y2 -= temp;
		temp = min(x1, x2);
		x1 -= temp;
		x2 -= temp;
		temp = min(z1, z2);
		z1 -= temp;
		z2 -= temp;
		temp = min(x1, y2);
		x1 -= temp;
		y2 -= temp;
		temp = min(z2, y1);
		ans -= temp * 2;
		cout << ans << endl;
	}
	return(0);
}