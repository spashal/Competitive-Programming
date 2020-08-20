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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		string s;
		cin >> s;
		n = s.size();
		ll anse = 0, anso = 0;
		vector< ll > last(10, -1);
		vector< vector< ll > > dp(n, vector< ll > (10, 0));
		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = 0 ; j < 10 ; j++){
				if( last[j] >= 0 and j != s[i] - '0' ){
					dp[i][j] = dp[last[j]][s[i] - '0'] + 1;
					if( dp[i][j] % 2 == 0 )
						anse = max(anse, dp[i][j]);
				}
				else if( last[j] < 0 )
					dp[i][j] = 1;
				if( j == s[i] - '0' ){
					if( last[j] >= 0 )
						dp[i][j] = dp[last[j]][j] + 1;
					anso = max(anso, dp[i][j]);
				}
			}
			last[s[i] - '0'] = i;
		}
		cout << min(n - anse, n - anso) << endl;
	}
	return(0);
}