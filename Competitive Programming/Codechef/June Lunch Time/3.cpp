#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
priority_queue< pair< ll, ll> > pq;
ll n, m, t, a[100005], p, po[32], ctr[32];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; fun(a[i]); }
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

void fun(ll a){
	for(int i = 0 ; a > 0 ; i++){
		if( a % 2 )
			ctr[i + 1]++;
		a /= 2;
	}
}
int main(){
	po[1] = 1;
	for(int i = 2 ; i < 31 ; i++)
		po[i] = po[i - 1] * 2;
	cin >> t;
	while( t-- ){
		cin >> n >> p;
		ari;
		ll ans = 0;
		ll temp = 1;
		for(int i = 1 ; i < 31 ; i++){
			pq.push(make_pair(ctr[i] * temp, 31 - i));
			temp *= 2;
			ctr[i] = 0;
		}
		for(int i = 0 ; i < p ; i++){
			ans += po[31 - pq.top().second];
			pq.pop();
		}
		cout << ans << endl;
		while( !pq.empty() )
			pq.pop();
	}
	return(0);
}