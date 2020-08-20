#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, dist[3003];
bool cycle[3003], vis[3003], on[3003];
vector< ll > adj[3003];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int dfs(int node, int parent){
	vis[node] = true;
	on[node] = true;
	int stop = 0;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if( !vis[adj[node][i]] ){
			stop = dfs(adj[node][i], node);
			if( stop )
				break;
		}
		else if( on[adj[node][i]] and adj[node][i] != parent ){
			cycle[node] = true;
			return adj[node][i];
		}
	}
	on[node] = false;
	if( stop > 0 ){
		if( stop == node ){
			cycle[node] = true;
			return 0;
		}
		else{
			cycle[node] = true;
			return stop;
		}
	}
	return 0;
}

void dffs(int node, int parDist){
	dist[node] = parDist + 1;
	vis[node] = true;
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( !vis[adj[node][i]] and !cycle[adj[node][i]] )
			dffs(adj[node][i], dist[node]);
}

void makeReady(){
	for(int i = 1 ; i <= n ; i++)
		vis[i] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    m = n;
    ginp;
    dfs(1, 0);
    for(int i = 1 ; i <= n ; i++){
    	if( cycle[i] ){
    		dist[i] = 0;
    		makeReady();
    		dffs(i, -1);
    	}
    }
    for(int i = 1 ; i <= n ; i++){
    	cout << dist[i] << " ";
    }
    cout << endl;
	return(0);
}