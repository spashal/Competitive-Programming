#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[35][35];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= m ; j++ )
				cin >> a[i][j];
		int ans = 0;
		int hell;
		if( (n+m) % 2 == 0 )
			hell = (n+m)/2;
		else
			hell = (n+m+2)/2;
		for( int k = 2 ; k <= hell ; k++ ){
			int one = 0, zero = 0;
			for( int i = 1 ; i <= n ; i++ )
				for( int j = 1 ; j <= m ; j++ )
					if( k == (i+j) or (n+m) - k + 2 == i+j ){
					if( a[i][j])
						one++;
					else
						zero++;
				}
			ans += min( one, zero );
		}
		cout << ans << endl;
	}
	return(0);
}