#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, dp[(1 << 21)], mod = 1e9 + 7;
bool com[21][21], inc[(1 << 21)][21];
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

//note that this same question could have been solved in just two for loops with o(10^7) but mine is
//more optimal :) but the other method is simpler to code I believe.
//PS: though on paper my time complexity is slightly better than n*2^n but in practice my code ran slower
//due to the fact that queues are slower than the array usage in increasing order(due to cache preferences).

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    	for(int j = 0 ; j < n ; j++)
    		cin >> com[i][j];
    dp[0] = 1;
	queue< pair< ll, ll> > q;
	q.push(make_pair(0, 0));
	while( !q.empty() ){
		ll mask = q.front().ff;
		ll cur = q.front().ss;
		q.pop();
		ll options = (1 << n) - 1 - mask;
		for(int i = 0 ; i < n ; i++){
			ll nxtMask = mask | (1 << i);
			if( (options & (1 << i)) > 0 and com[i][cur] ){
				dp[nxtMask] += dp[mask];
				dp[nxtMask] %= mod;
				if( cur < n - 1 and !inc[nxtMask][cur + 1] ){
					inc[nxtMask][cur + 1] = true;
					q.push(make_pair(nxtMask, cur + 1));
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
	return(0);
}