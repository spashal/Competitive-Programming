#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
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
		a[0] = 0;
		cin >> n >> m;
		ari;
		ll prev = 0, cur = 0, maxl = 0, peeps = 0;
		for(int i = 1 ; i <= n ; i++){
			cur += a[i];
			while( cur > m ){
				prev++;
				cur -= a[prev];
			}
			if( maxl < (i - prev) or( maxl == i - prev and peeps > cur ) ){
				peeps = cur;
				maxl = i - prev;
			}
		}
		cout << peeps << " " << maxl << endl;
	}
	return(0);
}