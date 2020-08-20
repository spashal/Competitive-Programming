#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, a[200005], b[200005], indeg[200005];
vector< ll > adj[100005];
#define ari for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
#define bri for( int i = 1 ; i <= n ; i++ ){ cin >> b[i]; if( b[i] != -1) indeg[b[i]]++; }
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
    cin >> n;
    ari;
    bri;
    ll finans = 0, inc = 0;
    vector< pair<ll, ll> > ans2;
    vector< ll > mark(n + 1, -1), par(n + 1, 0), t(n + 1, 0);
    vector< bool > vis(n + 1, false);
    priority_queue< pair<ll, ll> > pq;
    for(int i = 1 ; i <= n ; i++)
    	if( indeg[i] == 0 ){
    		vis[i] = true;
    		pq.push(mp(a[i], i));
    	}
    ll k = 0;
    while( inc < n ){
    	ll cur = pq.top().ss;
    	ll next = b[cur];
    	pq.pop();
    	inc++;
    	if( next == -1 ){
    		finans += a[cur];
    		mark[par[cur]] = cur;
    		t[k++] = cur;
    	}
    	else if( a[cur] < 0 and indeg[next] == 1 ){
    		vis[next] = true;
    		indeg[next] = 0;
    		// par[next] = cur;
    		// t[k++] = cur;
    		ans2.pb(mp(a[cur], cur));
    		pq.push(mp(a[next], next));
    	}
    	else if( a[cur] < 0 ){
    		if( next != -1 )
    			indeg[next]--;
    		ans2.pb(mp(a[cur], cur));
    		// t[k++] = cur;
    	}
	    else{
	    	finans += a[cur];
			a[next] += a[cur];
	    	mark[par[cur]] = cur;
	    	if( next > 0 ){
				indeg[next]--;
				t[k++] = cur;
				if( indeg[next] == 0 and !vis[next] ){
		    		vis[next] = true;
		    		par[next] = cur;
		    		k--;
		    		pq.push(mp(a[next], next));
				}
			}
    	}
    }
    sort(ans2.begin(), ans2.end(), greater< pair<ll, ll> > ());
    for(int i = 0 ; i < ans2.size() ; i++){
    	finans += ans2[i].ff;
    	mark[par[ans2[i].ss]] = ans2[i].ss;
    	t[k++] = ans2[i].ss;
    }
    cout << finans << endl;
    for(int i = 0 ; i < k ; i++){
   		int cur = t[i];
   		while( par[cur] != 0 )
   			cur = par[cur];
    	cout << cur << " ";
    	while( mark[cur] != -1 ){
   			cur = mark[cur];
    		cout << cur << " ";
    	}
    }
    cout << endl;
	return(0);
}
