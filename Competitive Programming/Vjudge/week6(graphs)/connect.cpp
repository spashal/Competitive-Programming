#include <bits/stdc++.h>
using namespace std;
bool vis1[51][51], vis2[51][51], a[51][51];
vector< pair< int, int> > adj[51][51];

void dfs1(int x, int y){
	vis1[x][y] = true;
	for(int i = 0 ; i < adj[x][y].size() ; i++)
		if( !vis1[adj[x][y][i].first][adj[x][y][i].second] )
			dfs1(adj[x][y][i].first, adj[x][y][i].second);
}

void dfs2(int x, int y){
	vis2[x][y] = true;
	for(int i = 0 ; i < adj[x][y].size() ; i++)
		if( !vis2[adj[x][y][i].first][adj[x][y][i].second] )
			dfs2(adj[x][y][i].first, adj[x][y][i].second);
}

int main(){
	int n, x1, x2, y1, y2;
	cin >> n;
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 0 ; i < n ; i++){
		string ss;
		cin >> ss;
		for(int j = 0 ; j < n ; j++){
			if( ss[j] == '0' )
				a[i][j] = false;
			else
				a[i][j] = true;
			vis1[i][j] = false;
			vis2[i][j] = false;
		}
	}
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			if( a[i][j] )
				continue;
			if( i > 0 and !a[i - 1][j] )
				adj[i][j].push_back(make_pair(i - 1, j));
			if( i + 1 < n and !a[i + 1][j] )
				adj[i][j].push_back(make_pair(i + 1, j));
			if( j > 0 and !a[i][j - 1] )
				adj[i][j].push_back(make_pair(i, j - 1));
			if( j + 1 < n and !a[i][j + 1] )
				adj[i][j].push_back(make_pair(i, j + 1));
		}
	x1--;x2--;y1--;y2--;
	dfs1(x1, y1);
	dfs2(x2, y2);
	int ans = INT_MAX;
	if( vis1[x2][y2] )
		cout << "0" << endl;
	else{
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++){
				if( !vis1[i][j] )
					continue;
				for(int k = 0 ; k < n ; k++)
					for(int l = 0 ; l < n ; l++)
						if( vis2[k][l] )
							ans = min(ans, (i - k) * ( i - k) + (j - l) * (j - l));
			}
		cout << ans << endl;
	}
	return(0);
}