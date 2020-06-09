#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
bool ultimate;
bool vis[50][50], abil[55][55];
string s[55];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> s[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

// Please note that this is not the tidiest of solutions and also not the most optimal. So just in case you might want to look at the blog.

void prep(){
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			vis[i][j] = false;
}

void dfs( ll i, ll j){
	vis[i][j] = true;
	if( i == n - 1 and j == m - 1 ){
		ultimate = true;
		vis[n-1][m-1] = true;
	}
	if( abil[i][j] ){
		ultimate = true;
		vis[n-1][m-1] = true;
	}
	if( i > 0 and s[i-1][j] != 'B' and s[i-1][j] != '#' and !vis[i-1][j] and !ultimate )
		dfs( i-1, j);
	if( i < n - 1 and s[i+1][j] != 'B' and s[i+1][j] != '#' and !vis[i+1][j] and !ultimate )
		dfs( i+1, j);
	if( j > 0 and s[i][j-1] != 'B' and s[i][j-1] != '#' and !vis[i][j-1] and !ultimate )
		dfs( i, j-1);
	if( j < m - 1 and s[i][j+1] != 'B' and s[i][j+1] != '#' and !vis[i][j+1] and !ultimate ){
		dfs( i, j+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		ari;
		int z = 0;
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ ){
				if( i > 0 and s[i][j] == 'B' ){
					if( s[i-1][j] == 'G' )
						z++;
					else if( s[i-1][j] != 'B' )
						s[i-1][j] = '#';
				}

				if( i < n - 1 and s[i][j] == 'B' ){
					if( s[i+1][j] == 'G' )
						z++;
					else if( s[i+1][j] != 'B' )
						s[i+1][j] = '#';
				}
				if( j > 0 and s[i][j] == 'B' ){
					if( s[i][j-1] == 'G' )
						z++;
					else if( s[i][j-1] != 'B' )
						s[i][j-1] = '#';
				}
				if( j < m - 1 and  s[i][j] == 'B' ){
					if( s[i][j+1] == 'G' )
						z++;
					else if( s[i][j+1] != 'B' )
						s[i][j+1] = '#';
				}			
			}
			// cout << "good" << endl;
		if( z == 0 ){
			for( int i = 0 ; i < n ; i++ ){
				for( int j = 0 ; j < m ; j++ )
					if( s[i][j] == 'G' ){
						// cout << i << " " << j << endl;
						prep();
						ultimate = false;
						dfs( i, j);
						if( !vis[n-1][m-1] )
							z++;
						else
							abil[i][j] = true;
					}
			}
			if( z )
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
		for( int i = 0 ; i < n ; i++ ){
			s[i].clear();
			for( int j = 0 ; j < m ; j++ )
				abil[i][j] = false;
		}
	}
	return(0);
}