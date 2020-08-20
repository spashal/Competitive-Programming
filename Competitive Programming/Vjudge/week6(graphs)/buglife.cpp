#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
vector< ll > adj[2003];
bool clr[2003], inc[2003];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int z = 1 ; z <= t ; z++){
    	cin >> n >> m;
    	bool flag = false;
    	for(int i = 1 ; i <= n ; i++){
    		inc[i] = false;
    		clr[i] = false;
    		adj[i].clear();
    	}
    	ginp;
    	for(int i = 1 ; i <= n ; i++){
    		if( inc[i] ) continue;
    		inc[i] = true;
    		clr[i] = false;
    		queue< pair< ll, ll> > q;
    		for(int k = 0 ; k < adj[i].size() ; k++){
    			q.push(mp(adj[i][k], 1));
    			inc[adj[i][k]] = true;
    			clr[adj[i][k]] = true;
    		}
    		while( !q.empty() ){
    			int node = q.front().ff;
    			int parclr = q.front().ss;
    			q.pop();
    			for(int j = 0 ; j < adj[node].size() ; j++){
    				if( !inc[adj[node][j]] ){
    					inc[adj[node][j]] = true;
    					clr[adj[node][j]] = 1 - parclr;
    					q.push(mp(adj[node][j], 1 - parclr));
    				}
    				else if( clr[adj[node][j]] == clr[node] )
    					flag = true;
    			}
    		}
    	}
    	cout << "Scenario #" << z << ":" << endl;
    	if( flag )
    		cout << "Suspicious bugs found!" << endl;
    	else
    		cout << "No suspicious bugs found!" << endl;

    }
	return(0);
}