#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ll tempo = n;
		ll a2 = 0, a3 = 0;
		ll temp = 1;
		while( n % 2 == 0 ){
			a2++;
			n /= 2;
			temp *= 2;
		}
		while( n % 3 == 0 ){
			a3++;
			n /= 3;
			temp *= 3;
		}
		if( temp != tempo or a2 > a3 )
			cout << "-1" << endl;
		else
			cout << 2 * a3 - a2 << endl;
	}
	return(0);
}