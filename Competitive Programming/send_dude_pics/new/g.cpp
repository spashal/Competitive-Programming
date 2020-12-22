#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, tyme[400005], cnt[400005], what[400005], cost[400005], anc[400005];
vector< ll > adj[400005];
bool visited[400005];
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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

void bfs(){
    queue< ll > q;
    vector< ll > vis(n + 1, 0);
    for(int i = 1 ; i <= n ; i++)
        if( !cnt[i] )
            q.push(i);
    while( !q.empty() ){
        ll node = q.front();
        q.pop();
        for(int i = 0 ; i < adj[node].size() ; i++){
            anc[adj[node][i]]++;
            vis[adj[node][i]]++;
            if( vis[adj[node][i]] == cnt[adj[node][i]] )
                q.push(adj[node][i]);
        }
    }
}

ll dfs(ll node){
    visited[node] = true;
    cost[node] = tyme[node] + anc[node];
    for(int i = 0 ; i < adj[node].size() ; i++)
        if( !visited[adj[node][i]] )
            cost[node] = max(cost[node], dfs(adj[node][i]));
        else
            cost[node] = max(cost[node], cost[adj[node][i]]);
    return cost[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector< ll > final;
    priority_queue< pair<ll, ll> > pq;
    for(int i = 1 ; i <= n ; i++){
    	ll nn, temp;
    	cin >> tyme[i] >> nn;
    	cnt[i] = nn;
    	for(int j = 0 ; j < nn ; j++){
    		cin >> temp;
    		adj[temp].pb(i);
    	}
    	if( nn == 0 )
    		pq.push(mp(tyme[i], i));
    }
    bfs();
    for(int i = 1 ; i <= n ; i++)
        if( !cnt[i] )
            dfs(i);
    while( !pq.empty() ){
    	ll node = pq.top().ss;
    	final.pb(node);
    	pq.pop();
    	for(int i = 0 ; i < adj[node].size() ; i++){
    		cnt[adj[node][i]]--;
            what[adj[node][i]] += what[node] + 1;
    		if( cnt[adj[node][i]] == 0 )
    			pq.push(mp(cost[adj[node][i]] - what[adj[node][i]], adj[node][i]));
    	}
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
    	ans = max(ans, i + tyme[final[i]]);
    cout << ans << endl;
	return(0);
}