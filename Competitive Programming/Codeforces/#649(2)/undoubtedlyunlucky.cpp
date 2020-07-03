#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int rec(int i, int j){
	if( a[i][0] == 0 and )
	if( a[i][0] < 2 and j < m ){
		a[i][j] = 0;
		a[i][0]--;
		return min( rec(n - i, j + 1) + i - 1, rec(n, j + 1) + n - i) + 2;
	}
}

int main(){
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ){
			cin >> a[i][j];
			a[i][0] += a[i][j];
		}
	cout << rec(1,1) + 1 << endl;
	return(0);
}