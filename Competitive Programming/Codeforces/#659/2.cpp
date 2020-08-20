#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[300005];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll l, k;
		cin >> n >> k >> l;
		ari;
		bool flag = false;
		for(int i = 1 ; i <= n ; i++){
			if( i % (2 * k) < k ){
				if( a[i - 1] + i % (2 * k) > l )
					flag = true;
			}
			else{
				if( a[i - 1] + (2 * k - i % (2 * k)) > l )
					flag = true;
			}
		}
		if( flag )
			cout << "No" << endl;
		else
			cout << "YES" << endl;
	}
	return(0);
}