#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
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
const ll INF = 1e18 + 18;
vector< vector< ll > > cost;
vector< ll > dp, pre;

void grp(ll i, ll taken, ll group, ll score, vector< ll > &available){
	if( i == (int)available.size() ){
		dp[taken] = max(dp[taken], score + pre[group]);
		return;
	}
	grp(i + 1, taken, group, score, available);
	grp(i + 1, taken | (1 << available[i]), group | (1 << available[i]), score, available);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cost.resize(n, vector< ll > (n));
    dp.resize((1 << n), -INF);
    pre.resize((1 << n), 0);

    for(int i = 0 ; i < n ; i++)
    	for(int j = 0 ; j < n ; j++)
    		cin >> cost[i][j];
    for(int mask = 0 ; mask < (1 << n) ; mask++)
    	for(int i = 0 ; i < n ; i++)
    		if( mask & (1 << i) )
    			for(int j = i + 1 ; j < n ; j++)
    				if( mask & (1 << j) )
	    				pre[mask] += cost[i][j];
    dp[0] = 0;
    for(int mask = 0 ; mask < (1 << n) ; mask++){
    	vector<ll> available;
    	for(int i = 0 ; i < n ; i++)
    		if( (mask & (1 << i)) == 0 )
    			available.pb(i);
    	grp(0, mask, 0, dp[mask], available);
    }
    cout << dp[(1 << n) - 1] << endl;
	return(0);
}