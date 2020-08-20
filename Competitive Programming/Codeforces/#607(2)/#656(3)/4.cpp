#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], po[22];
string s;
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

int binfn(int i, int k, int c){
	// if( dp[i][k][c - 'a'] != -1 )
	// 	return dp[i][k][c - 'a'];
	if( k == 0 ){
		if( c == (int)(s[i] - 'a') ){
			// dp[i][k][c - 'a'] = 0;
			return 0;
		}
		else{
			// dp[i][k][c - 'a'] = 1;
			return 1;
		}
	}
	int ans = 0;
	for(int j = 0 ; j < po[k - 1]; j++)
		if( s[j + i] - 'a' != c )
			ans++;
	ans += binfn(i + po[k - 1], k - 1, c + 1);
	int ctr = 0;
	for(int j = po[k - 1] ; j < po[k] ; j++)
		if( s[j + i] - 'a' != c )
			ctr++;
	ans = min(ctr + binfn(i, k - 1, c + 1), ans);
	// dp[i][k][c - 'a'] = ans;
	return ans;
}
int main(){
	po[0] = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1 ; i < 21 ; i++)
    	po[i] = 2 * po[i - 1];
	while( t-- ){
		cin >> n;
		s.clear();
		cin >> s;
		int ctr = 0;
		while(n > 0){
			n /= 2;
			ctr++;
		}

		cout << binfn(0, ctr - 1, 0) << endl;
	}
	return(0);
}