#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, T, t, k;
bool a, b;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> n >> m >> k;
	vector< ll > z, y, x;
	for(int i = 0 ; i < n ; i++){
		cin >> t >> a >> b;
		if( a and b )
			z.push_back(t);
		else if( a )
			x.push_back(t);
		else if(b)
			y.push_back(t);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	for(int i = x.size() - 1 ; i >= k ; i--)
		x.pop_back();
	for(int i = y.size() - 1 ; i >= k ; i--)
		y.pop_back();
	for(int i = z.size() - 1 ; i >= k ; i--)
		z.pop_back();
	ll ans = 0, inc = 0;
	ll j = 0, i = 0;
	while( inc < k and (i < min(x.size(), y.size()) or j < z.size() )){
		if( i < x.size() and i < y.size() and ( j >= z.size() or x[i] + y[i] < z[j] ) ){
			ans += x[i] + y[i];
			inc++;
			i++;
		}
		else if( j < z.size() ){
			ans += z[j];
			inc++;
			j++;
		}
	}
	if( inc == k );
	else
		ans = -1;
	cout << ans << endl;
	return(0);
}