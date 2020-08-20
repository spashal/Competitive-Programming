#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[200005], s1[200005], s2[200005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		ll max_ending_here = 0;
		ll max_so_far = 0;
		for(int i = 0 ; i + 1 < n ; i += 2){
			max_ending_here += a[i + 1] - a[i];
			max_ending_here = max(max_ending_here, (ll)0);
			max_so_far = max(max_so_far, max_ending_here);
		}
		max_ending_here = 0;
		for(int i = 1 ; i + 1 < n ; i += 2){
			max_ending_here += a[i] - a[i + 1];
			max_ending_here = max(max_ending_here, (ll)0);
			max_so_far = max(max_so_far, max_ending_here);
		}
		for(int i = 0 ; i < n ; i += 2)
			max_so_far += a[i];
		cout << max_so_far << endl;
	}
	return(0);
}