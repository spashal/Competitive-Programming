#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a, b, c, ar[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> a >> b >> c;
		if( a < c )
			cout << "1" << " ";
		else
			cout << "-1" << " ";
		if( c < b * a )
			cout << b << endl;
		// else if( c == b * a and b > 1 )
			// co
		else
			cout << "-1" << endl;
	}
	return(0);
}