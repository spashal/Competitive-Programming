#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[302][302], vis[102][102];
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

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				cin >> a[i][j];
		bool yes = true;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int ct = 0;
				if( i + 1 < n )
					ct++;
				if( i > 0 )
					ct++;
				if( j > 0 )
					ct++;
				if( j + 1 < m )
					ct++;
				if( a[i][j] <= ct )
					a[i][j] = ct;
				else
					yes = false;
			}
		}
		if( !yes )
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++)
					cout << a[i][j] << " ";
				cout << endl;
			}
		}
	}
	return(0);
}