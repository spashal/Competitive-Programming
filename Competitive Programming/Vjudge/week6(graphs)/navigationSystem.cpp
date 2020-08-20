#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, k, mini = 0, maxi = 0, dist[200005];
bool inc[200005];
vector< ll > adj[200005], rev[200005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); rev[v].pb(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue< ll > q;
    vector< ll > path;
    cin >> n >> m;
    ginp;
    cin >> k;
    for(int i = 0 ; i < k ; i++){
    	ll u;
    	cin >> u;
    	path.pb(u);
    }
    dist[path.back()] = 0;
    inc[path.back()] = true;
    q.push(path.back());
    while( !q.empty() ){
    	ll node = q.front();
    	q.pop();
    	for(int i = 0 ; i < rev[node].size() ; i++)
    		if( !inc[rev[node][i]] ){
    			dist[rev[node][i]] = dist[node] + 1;
    			inc[rev[node][i]] = true;
    			q.push(rev[node][i]);
       		}
    }
    for(int i = 0 ; i < k - 1 ; i++){
    	vector< pair< ll, ll> > temp;
    	for(int j = 0 ; j < adj[path[i]].size() ; j++)
    		if( adj[path[i]][j] == path[i + 1] )
    			temp.pb(make_pair(dist[adj[path[i]][j]], 1));
    		else
    			temp.pb(make_pair(dist[adj[path[i]][j]], 0));
    	sort(temp.begin(), temp.end(), greater< pair< ll, ll > > ());
    	if( temp.back().ff < dist[path[i + 1]] )
    		mini++;
    	if( temp.back().ss != 1 )
    		maxi++;
    }
    cout << mini << " " << maxi << endl;
	return(0);
}