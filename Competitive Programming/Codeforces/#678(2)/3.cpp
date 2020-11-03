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
ll dp[1001][1001];
int binomialCoeffUtil(int n, int k)
{
    // If value in lookup table then return
    if (dp[n][k] != -1) //     
        return dp[n][k];
 
    // store value in a table before return
    if (k == 0) {
    	cout << n << " " << k << endl;
        dp[n][k] = 1;
        return dp[n][k];
    }
     
    // store value in table before return
    if (k == n) {
        dp[n][k] = 1; 
        return dp[n][k];
    }
     
    // save value in lookup table before return
    dp[n][k] = (binomialCoeffUtil(n - 1, k - 1) +
               binomialCoeffUtil(n - 1, k)) % mod;
    return dp[n][k];
}
 
int binomialCoeff(int n, int k)
{
 
    // loop to create table dynamically   
    return binomialCoeffUtil(n, k);
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    t = 1;
    for(int i = 0 ; i < 1001 ; i++)
    	for(int j = 0 ; j < 1001 ; j++)
    		dp[i][j] = -1;
	while( t-- ){
		ll x, pos;
		cin >> n >> x >> pos;
		int k = log(x);
		ll ans = 1;
		for(int i = 1 ; i <= (n - k) ; i++)
			ans = (ans * i) % mod;
		cout << (binomialCoeff(n - 1, k - 1) * ans) % mod << endl;

	}
	return(0);
}