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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    vector< vector< pair<int, pair<int, int> > > > dp(a.size(), vector< pair<int, pair<int, int > > > (b.size(), mp(0, mp(-1, -1))));
	for(int i = a.size() - 1 ; i >= 0 ; i--)
		for(int j = b.size() - 1 ; j >= 0 ; j--)
			if(a[i] == b[j]){
				if(i < a.size() - 1 and j < b.size() - 1)
					dp[i][j] = mp(1 + dp[i+1][j+1].ff, mp(i+1, j+1));
				else
					dp[i][j].ff = 1;
			}
			else if( i < a.size() - 1 and j < b.size() - 1){
				if(dp[i+1][j].ff > dp[i][j+1].ff)
					dp[i][j] = mp(dp[i+1][j].ff, mp(i+1, j));
				else
					dp[i][j] = mp(dp[i][j+1].ff, mp(i, j+1));
			}
			else if(i < a.size() - 1)
				dp[i][j] = mp(dp[i+1][j].ff, mp(i+1, j));
			else if(j < b.size() - 1)
				dp[i][j] = mp(dp[i][j+1].ff, mp(i, j+1));
	pair<int, int> cur = dp[0][0].ss;
	string ans;
	if(a[0] == b[0])
		ans.pb(a[0]);
	while(cur.ff > -1 and cur.ss > -1){
		if(a[cur.ff] == b[cur.ss])
			ans.pb(a[cur.ff]);
		cur = dp[cur.ff][cur.ss].ss;
	}
	cout << ans << endl;
	return(0);
}