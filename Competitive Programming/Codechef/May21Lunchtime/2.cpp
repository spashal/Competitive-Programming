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
		ll k;
		cin >> n >> k;
		ari;
		sort(a, a + n, greater< ll > ());
		ll sum1 = 0, sum2 = 0;
		for(int i = 0 ; i < 2*k ; i += 2){
			sum1 += a[i];
		}
		for(int i = 1 ; i < 2*k ; i += 2)
			sum2 += a[i];
		sum2 += a[2*k];
		cout << max(sum1, sum2) << endl;
	}
	return(0);
}