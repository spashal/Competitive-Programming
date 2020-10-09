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
ll mod = 1e9 + 7;
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
void fun(ll &aka, ll c){
	ll exp = 3, exe = 1;
	while( c ){
		if( c % 2 )
			exe = (exe * exp) % mod;
		exp = (exp * exp) % mod;
		c /= 2;
	}
	aka = (aka * exe) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		cin >> n;
		string s;
		cin >> s;
		vector< vector <vector< ll > > > dp(5, vector< vector< ll > > (5, vector< ll > (5, 0)));
		for(int i = n - 1 ; i >= 0 ; i--){
			if( s[i] == 'c' )
				dp[3][0][0] = (dp[3][0][0] + 1) % mod;
			else if( s[i] == 'b' ){
				dp[2][3][0] = (dp[2][3][0] + dp[3][0][0]) % mod;
				dp[2][4][0] = (dp[2][4][0] + dp[4][0][0]) % mod;
			}
			else if( s[i] == '?' ){
				dp[4][4][4] = (dp[4][4][0] + dp[4][4][4]) % mod;
				dp[4][4][3] = (dp[4][4][3] + dp[4][3][0]) % mod;
				dp[4][2][4] = (dp[4][2][4] + dp[2][4][0]) % mod;
				dp[4][2][3] = (dp[4][2][3] + dp[2][3][0]) % mod;	
				dp[4][4][0] = (dp[4][4][0] + dp[4][0][0]) % mod;
				dp[4][0][0] = (dp[4][0][0] + 1) % mod;
				dp[4][3][0] = (dp[4][3][0] + dp[3][0][0]) % mod;

			}
			else{
				dp[1][4][4] = (dp[1][4][4] + dp[4][4][0]) % mod;
				dp[1][2][3] = (dp[1][2][3] + dp[2][3][0]) % mod;
				dp[1][4][3] = (dp[1][4][3] + dp[4][3][0]) % mod;
				dp[1][2][4] = (dp[1][2][4] + dp[2][4][0]) % mod;
			}
		}
		fun(dp[1][2][3], dp[4][0][0]);
		fun(dp[1][2][4], dp[4][0][0] - 1);
		fun(dp[1][4][4], dp[4][0][0] - 2);
		fun(dp[1][4][3], dp[4][0][0] - 1);
		fun(dp[4][2][3], dp[4][0][0] - 1);
		fun(dp[4][4][3], dp[4][0][0] - 2);
		fun(dp[4][2][4], dp[4][0][0] - 2);
		fun(dp[4][4][4], dp[4][0][0] - 3);
		cout << (dp[1][2][3] + dp[1][4][3] + dp[1][2][4] + dp[4][2][4] + dp[4][4][3] + dp[1][4][4] + dp[4][4][4] + dp[4][2][3]) % mod << "\n";
	return(0);
}