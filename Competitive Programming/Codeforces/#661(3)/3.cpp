#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
		cin >> n;
		vector< ll > a(n, 0);
		ari;
		sort(a.begin(), a.end());
		ll maxi = 0;
		for(int s = 2 ; s <= 2 * n ; s++){
			ll end = n - 1, start = 0, ctr = 0;
			while( end > start ){
				if( a[end] + a[start] == s ){
					end--;
					ctr++;
					start++;
				}
				else if( a[end] + a[start] > s )
					end--;
				else if( a[end] + a[start] < s )
					start++;
			}
			maxi = max(ctr, maxi);
		}
		cout << maxi << endl;
	}
	return(0);
}