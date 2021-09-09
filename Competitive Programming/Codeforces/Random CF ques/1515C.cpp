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
		ll x;
		cin >> n >> m >> x;
		vector< pair<ll, ll> > inp(n, mp(-1, -1));
		for(int i = 0 ; i < n ; i++){
			cin >> inp[i].first;
			inp[i].second = i;
		}
		sort(inp.begin(), inp.end());
		int ctr = 0;
		vector< int > ans(n, 0);
		for(int i = n-1 ; i >= 0 ; i--){
			ans[inp[i].second] = ++ctr;
			if(ctr == m){
				ctr = 0;
			}
		}
		cout << "YES\n";
		for(int i = 0 ; i < n ; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}