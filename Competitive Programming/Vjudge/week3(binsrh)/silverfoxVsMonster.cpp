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
    ll d, a, ans = 0;
    cin >> n >> d >> a;

    vector< pair<ll, ll> > in(n, mp(0, 0));
    vector< ll > x(n, 0), h(n, 0);
    
    for(int i = 0 ; i < n ; i++)
    	cin >> in[i].ff >> in[i].ss;
    
    sort(in.begin(), in.end());
    for(int i = 0 ; i < n ; i++)
    	x[i] = in[i].ss;
    
    for(int i = 0 ; i < n ; i++){
    	in[i].ss += h[i];
    	if( in[i].ss > 0 ){
    		
    		ll change = ceil((ld)in[i].ss / a);
    		ans += change;

    		if( i < n - 1 and in[i + 1].ff <= in[i].ff + 2 * d ){
    			h[i + 1] -= a * change;
    			vector< ll > :: iterator it;
    			it = upper_bound(x.begin() + i, x.end(), in[i].ff + 2 * d);
	    		if( it != x.end() )
    				h[it - x.begin()] += a * change;
    		}
    	}
    	if( i < n - 1 )
    		h[i + 1] += h[i];
    }
    cout << ans << endl;
	return(0);
}