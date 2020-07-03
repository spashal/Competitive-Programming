#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], b[100005];
bool inc[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; inc[a[i]] = true; }
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> n;
	ari;
	for( int i = 0 ; i < n ; i++ )
		b[i] = -1;
	int last = 0;
	if( a[0] == 1 ){
		b[0] = 0;
		last = 1;
		inc[0] = true;
	}
	int z = 0;
	for( int i = 1 ; i < n ; i++ ){
		if( a[i] != a[i-1] ){
			b[i] = a[i-1];
			inc[a[i-1]] = true;
		}
	}
	int j = 0;
	for( int i = 0 ; i < n ; i++ ){
		if( b[i] == -1 ){
			while( j <= n and inc[j] )
				j++;
			b[i] = j;
			inc[j] = true;
			j++;
		}
	}
	for( int i = 0 ; i < n ; i++ )
		cout << b[i] << " ";
	cout << endl;
	return(0);
}