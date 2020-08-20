#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, len1[800005], end1[800005], len2[800005];
vector< pair< ll, ll> > a(800005);
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i].ff >> a[i].ss;
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
	for(int r = 1 ; r <= t ; r++){
		cin >> n;								
		ari;
		sort(a.begin(), a.begin() + n);
		map<ll, ll> len1;
		map<ll, ll> len2;
		ll ans = 0;	
		for(int i = 0 ; i < n ; i++){
			len1[a[i].ff + a[i].ss] = max(len1[a[i].ff + a[i].ss], len1[a[i].ff] + a[i].ss);
			ans = max(ans, len1[a[i].ss + a[i].ff]);
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			len2[a[i].ff - a[i].ss] = max(len2[a[i].ff - a[i].ss], len2[a[i].ff] + a[i].ss);
			ans = max(ans, len2[a[i].ff - a[i].ss] + len1[a[i].ff - a[i].ss]);
		}
		cout << "Case #" << r << ": " << ans << endl;
	}
	return(0);
}