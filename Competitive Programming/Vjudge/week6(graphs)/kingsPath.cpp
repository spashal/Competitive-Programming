#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, x1, Y1, r, a, b, x2, y2;
queue< pair< ll, ll> > q;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ )mp( int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);)
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
    map< pair< ll, ll>, bool > nd, vis;
    map< pair< ll, ll>, ll> dist;
    cin >> x1 >> Y1 >> x2 >> y2;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
    	cin >> r >> a >> b;
    	for(int j = a ; j <= b ; j++){
    		nd[mp(r, j)] = true;
    		vis[mp(r, j)] = false;
    		dist[mp(r, j)] = INT_MAX;
    	}
    }
    int utilarrx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int utilarry[] = {1, -1, 0, 1, -1, 1, -1, 0};
    q.push(mp(x1, Y1));
    dist[mp(x1, Y1)] = 0;
    vis[mp(x1, Y1)] = true;
    while( !q.empty() ){
    	ll x = q.front().ff;
    	ll y = q.front().ss;
    	q.pop();
    	for(int i = 0 ; i < 8 ; i++){
    		if( x + utilarrx[i] > 0 and x + utilarrx[i] <= 1000000000 
    			and y + utilarry[i] > 0 and y + utilarry[i] <= 1000000000 
    			and nd[mp(x + utilarrx[i], y + utilarry[i])]  and !vis[mp(x + utilarrx[i], y + utilarry[i])] ){
    			vis[mp(x + utilarrx[i], y + utilarry[i])] = true;
    			dist[mp(x + utilarrx[i], y + utilarry[i])] = dist[mp(x, y)] + 1;
    			q.push(mp(x + utilarrx[i], y + utilarry[i]));
    		}
    	}
    }
    if( dist[mp(x2, y2)] < INT_MAX )
    	cout << dist[mp(x2, y2)] << endl;
    else
    	cout << "-1" << endl;
	return(0);
}