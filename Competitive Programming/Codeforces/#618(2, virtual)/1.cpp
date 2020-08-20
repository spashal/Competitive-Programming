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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		priority_queue< ll, vector< ll >, greater< ll > > ar;
		// sort(a, a + n);
		ll sum = 0;
		for(int i = 0 ; i < n ; i++){
			ar.push(llabs(a[i]));
			sum += a[i];
		}
		// sort(ar.begin(), ar.end());
		ll ans = 0;
		while( !ar.empty() and ar.top() == 0 ){
			ar.pop();
			sum++;
			ans++;
		}
		if( sum == 0 )
			ans++;
		cout << ans << endl;
	}
	return(0);
}