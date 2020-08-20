#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, parent[100005];
bool pushed[100005], c[100005], vis[100005];
priority_queue< ll, vector< ll >, greater< ll > > pq;
vector< ll > adj[100005], ans;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

void dfs(ll node){
	if( vis[node] )
		return;
	vis[node] = true;
	if( c[node] ){
		bool flag = false;
		for(int i = 0 ; i < adj[node].size() ; i++)
			if( adj[node][i] != parent[node] and !c[adj[node][i]] )
				flag = true;
		if( !flag ){
			pushed[node] = true;
			pq.push(node);
			for(int i = 0 ; i < adj[node].size() ; i++)
				if( adj[node][i] != parent[node] ){
					adj[parent[node]].pb(adj[node][i]);
					parent[adj[node][i]] = parent[node];
				}
		}
	}
	for(int i = 0 ; i < adj[node].size() ; i++)
		if( adj[node][i] != parent[node] )
			dfs(adj[node][i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll root = 0;
    for(int i = 1 ; i <= n ; i++){
    	cin >> parent[i] >> c[i];
    	if( parent[i] < 0 )
    		root = i;
    	if( parent[i] >= 0 )
    		adj[parent[i]].pb(i);
    }
    dfs(root);
    while( !pq.empty() ){
    	ans.pb(pq.top());
    	ll node = pq.top();
    	pq.pop();
    	for(int i = 0 ; i < adj[node].size() ; i++)
    		if( adj[node][i] != parent[node] ){
    			adj[parent[node]].pb(adj[node][i]);
    			parent[adj[node][i]] = parent[node];
    		}
    	vector< ll > :: iterator it;
    	if( !pushed[parent[node]] and c[parent[node]] ){
    		for(it = adj[parent[node]].begin() ; it < adj[parent[node]].end() ; it++)
    	    	if( *it == node ){
    	    		adj[parent[node]].erase(it);
    	   			break;
    	   		}
	    	bool flag = false;
	    	for(int i = 0 ; i < adj[parent[node]].size() ; i++)
	    		if( !c[adj[parent[node]][i]] )
	    			flag = true;
	    	if( !flag and !c[parent[node]] ){
	    		pushed[parent[node]] = true;
	    		pq.push(parent[node]);
	    	}
    	}
    }
    if( ans.size() > 0 ){
	    for(int i = 0 ; i < ans.size() ; i++)
    		cout << ans[i] << " ";
    	cout << endl;
    }
    else
    	cout << "-1" << endl; 
	return(0);
}