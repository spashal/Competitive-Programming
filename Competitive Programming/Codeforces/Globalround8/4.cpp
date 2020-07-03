#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[200005], ma = 0, check[(1 << 20)+1];
// vector< ll > adj[100005];
bool bits[20][200005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

void conv(int n, int k){
	for(int i = 0 ; i < 20 ; i++){
		if( n >= (1 << (19 - i)) )
			bits[19 - i][k] = true;
		else
			bits[19 - i][k] = false;
		n %= (1 << (19 - i));
	}
	// cout << n << " "
}

void back_conv(int k, ll& a){
	a = 0;
	for(int i = 0 ; i < 20 ; i++)
		a += (1 << i) * bits[i][k];
}

int main(){
	ll ans = 0;
	cin >> n;
	ari;
	// cout << "1" << endl;
	for(int i = 0 ; i < n ; i++)
		conv(a[i], i);
	// cout << "2" << endl;
	for(int i = 0 ; i < 20 ; i++)
		sort(bits[i], bits[i] + n, greater< bool > ());
	// cout << "3" << endl;
	for(int i = 0 ; i < n ; i++)
		back_conv(i, a[i]);
	// cout << "4" << endl;
	for(int i = 0 ; i < n ; i++)
		ans += a[i] * a[i];
	cout << ans << endl;
	return(0);
}