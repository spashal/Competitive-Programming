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
    vector< int > prime, factor(t+1, -1);
    vector< bool > visited(t + 1, false);
    for(int i = 2 ; i <= t ; i++){
    	if(!visited[i]){
    		prime.pb(i);
    		factor[i] = i;
    		for(int j = i*2 ; j <= t ; j += i){
    			visited[j] = true;
    			// cout << " quiet " << j << " " << i << endl;
    			factor[j] = i;
    		}
    	}
    }
    // for(int i = 1 ; i <= 10 ; i++)
    // 	cout << factor[i] << " ";
    // cout << endl;
    ll mod = 998244353;
	vector< ll > dp(t + 1, 0);
	dp[1] = 1;
	ll sum = 1;
	for(int i = 2 ; i <= t ; i++){
		// cout << endl << i << endl;
		// calculate no. of factors
		int num = i;
		int factors = 1;
		while(num > 1){
			int cnt = 0;
			int temp = num;
			// cout << factor[temp] << " factors" << endl;
			while(num % factor[temp] == 0){
				num /= factor[temp];
				cnt++;
				// cout << num << " num is here " << endl;
			}
			factors = (factors * (cnt + 1)) % mod;
		}
		// cout << factors << " haha " << endl;
		dp[i] = (sum + factors) % mod;
		sum = (sum + dp[i]) % mod;
	}
	cout << dp[t] << endl;
	return(0);
}