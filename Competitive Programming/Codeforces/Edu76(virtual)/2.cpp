#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x, y, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> x >> y;
		if( x == 1 ){
			if( y == 1 )
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else if( x == 2 or x == 3 ){
			if( y < 4 )
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else
			cout << "yes" << endl;
 	}
	return(0);
}