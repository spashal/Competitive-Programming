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
		cin >> n;
		n *= 2;
		ari;
		vector< int > ar, dp(2 * n + 1, 0);
		int prev = 0;
		for(int i = 0 ; i < n ; i++)
			if( prev < a[i] ){
				prev = a[i];
				ar.pb(1);
			}
			else
				ar[ar.size() - 1]++;
		sort(ar.begin(), ar.end());
		int max_yet = 0;
		dp[0] = 1;
		for(int i = 0 ; i < ar.size() ; i++){
			for(int sum = max_yet ; sum >= 0 ; sum--)
				dp[sum + ar[i]] += min(5, dp[sum]);
			max_yet += ar[i];
		}
		if( dp[n / 2] )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return(0);
}