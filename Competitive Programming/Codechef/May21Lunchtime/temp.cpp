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
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		ari;
		ll curSum = 0, maxSum = 0;
		ll maxele = INT_MIN;
		vector< vector<ll> > dp(m, vector< ll > (n, 0));
		vector< ll > dpback(n, 0);
		for(int i = 0 ; i < n ; i++){
			curSum += a[i];
			maxele = max(maxele, a[i]);
			curSum = max((ll)0, curSum);
			maxSum = max(maxSum, curSum);
			if(maxele < 0){
				dp[0][i] = maxele;
			}
			else
				dp[0][i] = maxSum;
		}
		curSum = maxSum = 0;
		maxele = INT_MIN;
		for(int i = n - 1 ; i > 0 ; i--){
			curSum += a[i];
			maxele = max(maxele, a[i]);
			curSum = max((ll)0, curSum);
			maxSum = max(maxSum, curSum);
			if(maxele < 0){
				dpback[i-1] = maxele;
			}
			else
				dpback[i-1] = maxSum;
		}
		cout << "haha" << endl;
		ll ans = INT_MIN;
		for(int i = 1 ; i < m ; i++){
			for(int j = 0 ; j < n - i ; i++)
				dp[i][j] = dp[i-1][j] + (ll)(i+1)*(dpback[j]);
		}
		cout << "kaka" << endl;
		for(int i = 0 ; i < n ; i++){
			ans = min(dp[m-1][i], ans);
		}
		cout << ans << endl;
	}
	return(0);
}