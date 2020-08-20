#include <bits/stdc++.h>
using namespace std;
bool vis[11][11][11];
int T = 0, a, b, c, y, z;
string s[11][11];
void dfs(int X, int Y, int Z){
	vis[X][Y][Z] = true;
	T++;
	if( X > 0 and !vis[X - 1][Y][Z] and s[X - 1][Y][Z] == '.' )
		dfs(X - 1, Y, Z);
	if( Y > 0 and !vis[X][Y - 1][Z] and s[X][Y - 1][Z] == '.' )
		dfs(X, Y - 1, Z);
	if( Z > 0 and !vis[X][Y][Z - 1] and s[X][Y][Z - 1] == '.' )
		dfs(X, Y, Z - 1);
	if( X + 1 < a and !vis[X + 1][Y][Z] and s[X + 1][Y][Z] == '.' )
		dfs(X + 1, Y, Z);
	if( Y + 1 < b and !vis[X][Y + 1][Z] and s[X][Y + 1][Z] == '.' )
		dfs(X, Y + 1, Z);
	if( Z + 1 < c and !vis[X][Y][Z + 1] and s[X][Y][Z + 1] == '.' )
		dfs(X, Y, Z + 1);
}

int main(){
	cin >> a >> b >> c;
	for(int i = 0 ; i < a ; i++)
		for(int j = 0 ; j < b ; j++)
			cin >> s[i][j];
	cin >> y >> z;
	dfs(0, y - 1, z - 1);
	cout << T << endl;
}