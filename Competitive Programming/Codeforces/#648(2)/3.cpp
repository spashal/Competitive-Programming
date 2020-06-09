#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[200005], b[200005], c[200005], d[400005], n, m, t;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; c[a[i]] += i; }
#define bri for( int i = 0 ; i < n ; i++ ){ cin >> b[i]; c[b[i]] -= i; }
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
		cin >> n;
		ari; bri;
		int mai = 0;
		for( int i = 1 ; i <= n ; i++ ){
			c[i] += n;
			c[i] %= n;
			// cout << c[i] << " ";
			d[200000+c[i]]++;
		}
		for( int i = 0 ; i <= 400000 ; i++ )
			mai = max( d[i], mai);
cout << mai << endl;
	return(0);
}