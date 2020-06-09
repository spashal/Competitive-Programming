#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100005], n, m, t;
vector< ll > adj[100005];
bool b[55][55];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		ll r = 0, c = 0;
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				cin >> b[i][j];
		for( int i = 0 ; i < n ; i++ ){
			int z = 0;
			for( int j = 0 ; j < m ; j++ )
				if( b[i][j] )
					z++;
			if( !z )
				r++;
		}
		for( int i = 0 ; i < m ; i++ ){
			int z = 0;
			for( int j = 0 ; j < n ; j++ )
				if( b[j][i] )
					z++;
			if( !z )
				c++;
		}
		if( min( c, r) % 2 )
			cout << "Ashish" << endl;
		else
			cout << "Vivek" << endl;
	}
	return(0);
}