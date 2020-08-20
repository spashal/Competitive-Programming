#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
ld n, m, t, a[100005];
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

int main(){
	ld teq, t1, k, d, ans = 0;
	cin >> k >> d >> t;
	if( k > d and (ll)k % (ll)d )
		teq = d - (ll)k % (ll)d;
	else if( k > d )
		teq = 0;
	else
		teq = d - k;
	ld r =floor(t / (k + teq / 2));
	t1 = t - r * (k + teq / 2);
	if( t1 <= k )
		ans = (ld)r * ((ld)k + teq) + (ld)t1;
	else
		ans = (ld)r * ((ld)k + teq) + 2 * t1 - k;
	cout << fixed << setprecision(10) << ans << endl;
	return(0);
}