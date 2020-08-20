#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
string s[1001], ans;
ll dist[1000][1000], a, b, k, n, m;
queue< pair< ll, ll> > q;
bool vis[1000][1000];
int utily[] = {0, -1, 1, 0}, utilx[] = {1, 0, 0, -1};

int main(){
	string charr;
	charr.pb('D');
	charr.pb('L');
	charr.pb('R');
	charr.pb('U');
	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i];
		for(int j = 0 ; j < m ; j++){
			if( s[i][j] == 'X' ){
				a = i;
				b = j;
			}
			vis[i][j] = false;
		}
	}
	q.push(mp(a, b));
	dist[a][b] = 0;
	while( !q.empty() ){
		ll x = q.front().ff;
		ll y = q.front().ss;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			if( x + utilx[i] >= 0 and x + utilx[i] < n 
				and y + utily[i] >= 0 and y + utily[i] < m 
				and s[x + utilx[i]][y + utily[i]] == '.'
				and !vis[x + utilx[i]][y + utily[i]] ){
				vis[x + utilx[i]][y + utily[i]] = true;
				q.push(mp(x + utilx[i], y + utily[i]));
				dist[x + utilx[i]][y + utily[i]] = dist[x][y] + 1;
			}
		}
	}
	ll curx = a, cury = b;
	for(int i = 1 ; i <= k ; i++){
		for(int j = 0 ; j < 4 ; j++){
			ll x = curx + utilx[j];
			ll y = cury + utily[j];
			if( x >= 0 and x < n and y >= 0 and y < m 
				and s[x][y] != '*' and dist[x][y] + i <= k ){
				ans.pb(charr[j]);
				curx = x;
				cury = y;
				break;
			}
		}
	}
	if( ans.size() < k )
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;
	return(0);
}