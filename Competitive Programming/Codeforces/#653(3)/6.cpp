#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, x, y, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> x >> y >> n;
		if( n % x == y )
			cout << n << endl;
		else{
			if( n % x > y )
				cout << n - n % x + y << endl;
			else
				cout << n - x + y - n % x << endl;
		}
	}
	return(0);
}