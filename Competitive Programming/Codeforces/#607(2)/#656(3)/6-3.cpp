#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, k, leaves[200005];
queue< ll > q;
vector< set < ll > > adj(200005, set< ll > ());
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].insert(v); adj[v].insert(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first      // this is the accepted code!!!!!!!
#define sss second.second
#define sf second.first
#define mp make_pair

void checkPar(ll node){
	if( adj[node].size() == 1 ){
		leaves[*adj[node].begin()]++;
		if( leaves[*adj[node].begin()] >= k ){
			leaves[*adj[node].begin()] -= k;
			q.push(*adj[node].begin());
		}
	}
}

void rem(ll node){
	int ctr = 0;
	set< ll > :: iterator it;
	queue< ll > q;
	for(it = adj[node].begin() ; it != adj[node].end() ; it++){
		if( adj[*it].size() == 1 and ctr < k ){
			ctr++;
			q.push(*it);
			adj[*it].clear();
		}
		else if( ctr == k )
			break;
	}
	while( !q.empty() ){
		adj[node].erase(adj[node].lower_bound(q.front()));
		q.pop();
	}
	checkPar(node);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> k;
		m = n - 1;
		for(int i = 1 ; i <= n ; i++){
			leaves[i] = 0;
			adj[i].clear();
		}		ginp;
		for(int i = 1 ; i <= n ; i++)
			if( adj[i].size() == 1 )
				leaves[*adj[i].begin()]++;
		for(int i = 1 ; i <= n ; i++)
			if( leaves[i] >= k ){
				leaves[i] -= k;
				q.push(i);
			}
		ll ans = 0;
		while( !q.empty() ){
			ll node = q.front();
			q.pop();
			rem(node);
			if( leaves[node] >= k ){
				leaves[node] -= k;
				q.push(node);
			}
			ans++;
		}
		cout << min(n - 1, ans) << endl;
		while( !q.empty() )
			q.pop();
	}
	return(0);
}