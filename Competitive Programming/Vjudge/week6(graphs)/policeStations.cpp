#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, d, m, k, t, a;
bool vis[300005], ps[300005], inc[300005];
vector< ll > adj[300005], polSta, ans;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); adj[u].push_back(i); adj[v].push_back(i);}
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
    cin >> n >> k >> d;
    for(int i = 0 ; i < k ; i++){
    	cin >> a;
    	ps[a] = true;
    	polSta.pb(a);
    }
    m = n - 1;
    ginp;
    queue< pair< ll, ll > > q;
    for(int i = 0 ; i < k ; i++)
    	if( !vis[polSta[i]] ){
    	q.push(mp(polSta[i], 0));
    	vis[polSta[i]] = true;
    }
    while( !q.empty() ){
    	ll node = q.front().ff;
    	ll dist = q.front().ss;
    	q.pop();
    	if( dist == d ){
    		for(int i = 0 ; i < adj[node].size() ; i += 2)
				if( !inc[adj[node][i + 1]] ){
					inc[adj[node][i + 1]] = true;
					ans.pb(adj[node][i + 1]);
				}
    	}
    	else{
    		for(int i = 0 ; i < adj[node].size() ; i += 2){
    			if( !vis[adj[node][i]] ){
    				inc[adj[node][i + 1]] = true;
    				vis[adj[node][i]] = true;
    				q.push(mp(adj[node][i], dist + 1));
    			}
    			else if( vis[adj[node][i]] and !inc[adj[node][i + 1]] ){
    				inc[adj[node][i + 1]] = true;
    				ans.pb(adj[node][i + 1]);    				
    			}
    		}
    	}
    }
    cout << (int)ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size() ; i++)
    	cout << ans[i] + 1 << " ";
    cout << endl;
	return(0);
}