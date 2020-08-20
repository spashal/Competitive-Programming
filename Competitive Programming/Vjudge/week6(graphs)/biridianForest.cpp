#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m, t, me, ee, r, c, C[1000006], dist[1000006];
bool vis[1000006];
vector< int > adj[1000006];
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

void bfs(int node){
    queue< pair< ll, ll> > q;
    q.push(mp(node, 0));
    dist[node] = 0;
    vis[node] = true;
    while( !q.empty() ){
        node = q.front().ff;
        ll parDist = q.front().ss;
        q.pop();
        for(int i = 0 ; i < adj[node].size() ; i++)
            if( !vis[adj[node][i]] ){
                dist[adj[node][i]] = parDist + 1;
                vis[adj[node][i]] = true;
                q.push(mp(adj[node][i], dist[adj[node][i]]));
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    string s[r + 1];
    for(int i = 0 ; i < r ; i++)
    	cin >> s[i];
    for(int i = 0 ; i < r ; i++)
    	for(int j = 0 ; j < c ; j++){
            dist[i * c + j] = INT_MAX;
    		if( s[i][j] == 'T' )
    			continue;
    		if( i > 0 and s[i - 1][j] != 'T' )
    			adj[i * c + j].pb((i - 1) * c + j);
    		if( i + 1 < r and s[i + 1][j] != 'T' )
    			adj[i * c + j].pb((i + 1) * c + j);
    		if( j > 0 and s[i][j - 1] != 'T' )
    			adj[i * c + j].pb(i * c + j - 1);
    		if( j + 1 < c and s[i][j + 1] != 'T' )
    			adj[i * c + j].pb(i * c + j + 1);
    		if( s[i][j] !=  'S' and s[i][j] != 'E' )
    			C[i * c + j] = s[i][j] - '0';
    		else if( s[i][j] != 'E' ){
    			C[i * c + j] = 0;
    			me = i * c + j;
    		}
    		else{
    			ee = i * c + j;
    			C[ee] = 0;
    		}
    	}
    int ans = 0;
    bfs(ee);
    for(int i = 0 ; i < (r * c) ; i++)
    	if( dist[i] <= dist[me] and vis[i] )
    		ans += C[i];
    cout << ans << endl;
	return(0);
}