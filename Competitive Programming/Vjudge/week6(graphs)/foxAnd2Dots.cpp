#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
bool has[26], vis[51][51], on[51][51], ext = false;
string str;
vector< vector< ll > > s(51, vector< ll > (51, 0));
vector< pair< ll, ll> > adj[51][51];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

void dfs(ll x, ll y, pair< ll, ll> parent){
	vis[x][y] = true;
	on[x][y] = true;
	for(int i = 0 ; i < adj[x][y].size() ; i++){
		if( ext )
				return;
		if( !vis[adj[x][y][i].ff][adj[x][y][i].ss] )
			dfs(adj[x][y][i].ff, adj[x][y][i].ss, make_pair(x, y));
		else if( on[adj[x][y][i].ff][adj[x][y][i].ss] and adj[x][y][i] != parent ){
			cout << "Yes" << endl;
			ext = true;
			return;
		}
	}
	on[x][y] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
    	cin >> str;
    	for(int j = 0 ; j < m ; j++)
    		s[i][j] = str[j] - 'A';
    }
    for(int i = 0 ; i < n ; i++)
    	for(int j = 0 ; j < m ; j++){
    		has[s[i][j]] = true;
    		if( i > 0 and s[i - 1][j] == s[i][j] )
    			adj[i][j].pb(make_pair(i - 1, j));
    		if( i + 1 < n and s[i + 1][j] == s[i][j] )
    			adj[i][j].pb(make_pair(i + 1, j));
    		if( j > 0 and s[i][j - 1] == s[i][j] )
    			adj[i][j].pb(make_pair(i, j - 1));
    		if( j + 1 < m and s[i][j + 1] == s[i][j] )
    			adj[i][j].pb(make_pair(i, j + 1));
       	}
    for(int k = 0 ; k < 26 ; k++){
    	if( !has[k] )
    		continue;
    	for(int i = 0 ; i < n ; i++)
    		for(int j = 0 ; j < m ; j++)
    			if( !vis[i][j] and s[i][j] == k ){
    				dfs(i, j, make_pair(-1, -1));
    				if( ext )
    					return(0);
    			}
    }
    cout << "No" << endl;
	return(0);
}