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
		cin >> n;
		ari;
		sort(a, a + n);
		vector< ll > len;
		for(int i = 0 ; i < n - 1 ; i++)
			len.pb(a[i+1]-a[i]);
		ll ans = 0;
		for(int i = 0 ; i < len.size() ; i++){
			ans += len[i]*((i+1)*(n-i-1)-1);
		}
		cout << -ans << endl;
	}
	return(0);
}