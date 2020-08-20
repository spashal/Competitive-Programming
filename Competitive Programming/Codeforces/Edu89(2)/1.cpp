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
		cin >> n >> m;
		if( n == 0 or m == 0 )
			cout << "0" << endl;
		else if( n > 2 * m or m > 2 *  ){
			if( n > 2 * m)
				cout << m << endl;
			else
				cout << n << endl;
		}
		else
			cout << ( n + m) / 3 << endl;
 	}
	return(0);
}