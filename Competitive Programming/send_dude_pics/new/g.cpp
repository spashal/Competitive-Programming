#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, tyme[400005], cnt[400005];
vector< ll > adj[400005];
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
    while( !pq.empty() ){
    	ll node = pq.top().ss;
    	final.pb(node);
    	pq.pop();
    	for(int i = 0 ; i < adj[node].size() ; i++){
    		cnt[adj[node][i]]--;
    		if( cnt[adj[node][i]] == 0 )
    			pq.push(mp(tyme[adj[node][i]], adj[node][i]));
    	}
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
    	ans = max(ans, i + tyme[final[i]]);
    cout << ans << endl;
	return(0);
}