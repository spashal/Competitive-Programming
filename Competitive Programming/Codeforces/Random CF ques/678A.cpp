#include <bits/stdc++.h>
using namespace std;
int s[100005], g1 = 0, n, m, g2 = 0;

int main(){
	cin >> n >> m;
	int z = 0;
	vector< int > adj[100005];
	for( int i = 0 ; i < m ; i++ ){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for( int i = 1 ; i <= n ; i++ ){
		if( adj[i].size() == 0 )
			k++;
		else{
			if( !g1 and !g2 ){
				s[i] = 1;
				for( int j = 0 ; j < adj[i].size() ; j++ ){
					s[adj[i][j]] = 2;
					g2++;
				}
				g1++;
			}
			else if( !s[i] ){
				int l1 = 0, l2 = 0;
				for( int j = 0 ; j < adj[i].size() ; j++ ){
					if( s[adj[i][j]] == 1 )
						l1++;
					else if( s[adj[i][j]] == 2 )
						l2++;
				}
				if( l1 and !l2 ){
					for( int j = 0 ; j < adj[i].size() ; j++ ){
						s[adj[i][j]] = 1;
						g1++;
					}
					s[i] = 2;
					g2++;
				}
				else if( !l1 and l2 ){
					s[i] = 1;
					for( int j = 0 ; j < adj[i].size() ; j++ ){
						s[adj[i][j]] = 2;
						g2++;
					}
					g1++;
				}
				else{
					z = 1;
					break;
				}
			}
			else{
				for( int j = 0 ; j < adj[i].size() ; j++ )
					if( s[adj[i][j]] != s[i] )
						s[adj[i][j]] = 3 - s[i];
					else{
						z = 1;
						break;
					}
				if( s[i] == 1 ){
					g1++;
					g2 += (int)adj[i].size();
				}
				else{
					g2++;
					g1 += (int)adj[i].size();
				}
			}
		}
	}
	if( z == 1 )
		cout << "-1" << endl;
	else if( g1 and g2 ){
		cout << g1 << endl;
		for( int i = 1 ; i <= n ; i++ )
			if( s[i] == 1 )
				cout << i << " ";
		cout << endl << g2 << endl;
		for( int i = 1 ; i <= n ; i++ )
			if( s[i] == 2 )
				cout << i << " ";
		cout << endl;
	}
	else if( !g1 ){
		
	}
	return(0);
}