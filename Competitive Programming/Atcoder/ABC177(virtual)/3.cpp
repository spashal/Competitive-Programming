#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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

ll fast(){
	ll temp = 1, exp = 1e9 + 5, pow = 2;
	while( exp > 0 ){
		if( exp % 2 )
			temp = (temp * pow) % mod;
		exp /= 2;
		pow = (pow * pow) % mod; 
	}
	return temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ari;
    ll sum = 0, sq = 0;
    for(int i = 0 ; i < n ; i++){
    	sum += a[i];
    	sum %= mod;
    	sq += (a[i] * a[i]) % mod;
    	sq %= mod;
    }
    ll ans = (((sum * sum) % mod - sq) + mod) % mod;
    ans = (ans * fast()) % mod;
    cout << ans << endl;
	return(0);
}