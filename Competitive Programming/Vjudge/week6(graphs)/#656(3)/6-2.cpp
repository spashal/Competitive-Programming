#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n, m, t, k, leaves[200005];
bool inc[200005];
vector< ll > adj[200005];
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
queue< ll > q;
priority_queue< pair< ll, ll> > pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> k;
		m = n - 1;
		for(int i = 1 ; i <= n ; i++)
			adj[i].clear();
		ginp;
		for(int i = 1 ; i <= n ; i++){
			inc[i] = false;
			leaves[i] = 0;
		}
		for(int i = 1 ; i <= n ; i++)
			if( adj[i].size() == 1 ){
				inc[i] = true;
				leaves[adj[i][0]]++;
			}
		
		for(int i = 1 ; i <= n ; i++)
			if( leaves[i] >= k ){
				leaves[i] -= k;
				q.push(i);
			}
		ll ans = 0;
		while( !q.empty() ){
			ll node = q.front();
			if( leaves[node] == 0 )
				inc[node] = true;
			q.pop();
			if( leaves[node] == 0 )
				for(int i = 0 ; i < adj[node].size() ; i++)
					if( !inc[adj[node][i]] ){
						leaves[adj[node][i]]++;
						if( leaves[adj[node][i]] >= k ){
							leaves[adj[node][i]] -= k;
							q.push(adj[node][i]);
						}
						break;
					}
			if( leaves[node] >= k ){
				leaves[node] -= k;
				q.push(node);
			}
			ans++;
		}
		cout << min( n - 1, ans) << endl;
	}
	return(0);
}
