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
		ll r, g, b, w;
		cin >> r >> g >> b >> w;
		if( (r % 2) + (g % 2) + (b % 2) + (w % 2) <= 1 ){
			cout << "yes" << endl;
			continue;
		}
		if( min(r, min(g, b)) > 0 and (r - 1) % 2 + (g - 1) % 2 + (b - 1) % 2 + (w + 3) % 2 < 2 )
			cout << "yes" << endl;
		else
			cout << "no" <<endl;
	}
	return(0);
}