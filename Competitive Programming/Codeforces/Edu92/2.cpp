#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, k, z, a[100005], sum[100005];
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
		vector< ll > ans;
		vector< pair<ll, ll> > ar;
		cin >> n >> k >> z;
		ari;
		sum[0] = a[0];
		for(int i = 0 ; i < k ; i++){
			sum[i + 1] = sum[i] + a[i + 1];
			ar.pb(mp((a[i] + a[i + 1]), -1 * i ));
		}
		sort(ar.begin(), ar.end(), greater< pair<ll, ll> > ());
		for(int i = 0 ; i <= z ; i++){
			int s = 0;
			while( s < ar.size() and -1 * ar[s].ss > k - 2 * i )
				s++;
			if( s < ar.size() )
				ans.pb(sum[k - 2 * i] + i * ar[s].ff);
		}
		sort(ans.begin(), ans.end(), greater< ll > ());
		cout << ans[0] << endl;
	}
	return(0);
}