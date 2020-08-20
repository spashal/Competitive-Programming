#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
vector< ll > dp(100, 0), adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
const ll mod = 1e9 + 7;

void self_sum(ll& a, ll b){
	a += b;
	if( a >= mod )
		a -= mod;
}

// This solution was originally inspired by errichto's but I couldn't understand a few of his steps
// so I followed from his steps and did it. I think he was doing it by some standard problem type and
// it is advisable to read about that standard type.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll D, len, extreme = 0;
    cin >> s;
    cin >> D;
    len = s.size();
    dp[0] = 1;
    for(int cur = 0 ; cur < len ; cur++){
    	vector< ll > new_dp(100, 0);
    	if( cur > 0 )
	    	for(int sum = 0 ; sum < D ; sum++)
    			for(int digit = 0 ; digit < 10 ; digit++)
					self_sum(new_dp[(sum + digit) % D], dp[sum]);

    	dp = new_dp;
    	for(int digit = 0 ; digit < 10 ; digit++)
    		if( digit < s[cur] - '0' )
    			self_sum(dp[(extreme + digit) % D], 1);
    	self_sum(extreme, (ll)(s[cur] - '0'));
    	extreme %= D;
    }
    self_sum(dp[extreme], 1);
    dp[0]--;
    if( dp[0] == -1 )
    	dp[0] = mod - 1;
    cout << dp[0] << endl;
   	return(0);
}