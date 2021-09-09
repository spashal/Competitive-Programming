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
    cin >> n;
    vector< vector< bool > > compatibility(n, vector<bool> (n, false));
    for(int i = 0 ; i < n ; i++)
    	for(int j = 0 ; j < n ; j++){
    		int aa;
    		cin >> aa;
    		compatibility[i][j] = aa;
    	}
    vector< ll > dp((1 << n), 0);
    dp[0] = 1;
    ll mod = 1e9+7;
    ll max = (1 << n);
	for(ll mask = 1 ; mask < max ; mask++){
		int cur = 0;
		for(int i = 0 ; i < n ; i++)
			if((mask & (1 << i)))
				cur++;
		cur--;
		for(int j = 0 ; j < n ; j++)
			if(compatibility[cur][j] and (mask & (1 << j)))
				dp[mask] = (dp[mask] + dp[(mask ^ (1 << j))]) % mod;
	}
    cout << dp[max-1] << endl;
	return(0);
}