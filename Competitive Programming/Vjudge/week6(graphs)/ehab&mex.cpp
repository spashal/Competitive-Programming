#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, Time, root = 0, dist[100005], mex[100005];
bool vis[100005];
queue< ll > q;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define pb push_back
#define ginp for( int i = 0 ; i < m ; i++ ){ mex[i + 1] = -1;int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); adj[u].pb(i + 1); adj[v].pb(i + 1);}
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    m = n - 1;
    ginp;
    for(int i = 1 ; i <= n ; i++)
    	if( adj[i].size() >= 6 ){
    		root = i;
    		break;
    	}
    Time = 0;
    if( root ){
    	for(int i = 1 ; i < adj[root].size() ; i += 2)
    		mex[adj[root][i]] = Time++;
    }
    for(int i = 1 ; i < n ; i++)
   		if( mex[i] == -1 )
  			mex[i] = Time++;
    for(int i = 1 ; i < n ; i++)
    	cout << mex[i] << endl;
	return(0);
}