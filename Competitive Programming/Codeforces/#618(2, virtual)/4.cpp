#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], b[100005];
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
    cin >> n;
    ll ctr = 0;
    for(int i = 0 ; i < n ; i++)
    	cin >> a[i] >> b[i];
    if( n % 2 == 0 )
	    for(int i = 0 ; i < (n / 2) ; i++){
	    	if( b[i] == b[i + 1]){
	    		if( b[i + n / 2] == b[(i + n / 2 + 1) % n] and llabs(a[i] - a[i + 1]) == llabs(a[i + n / 2] - a[(i + n / 2 + 1) % n]) )
	    			ctr++;
	    		continue;
	    	}
	    	ld slope1 = (ld)(a[i] - a[i + 1]) / (b[i] - b[i + 1]);
	    	ll dist1 = (a[i] - a[i + 1]) * (a[i] - a[i + 1]) + (b[i] - b[i + 1]) * (b[i] - b[i + 1]);
	    	ld slope2 = (ld)(a[(i + n / 2) % n] - a[(i + 1 + n / 2) % n]) / (b[(i + n / 2) % n] - b[(i + 1 + n / 2) % n]);
	    	ll dist2 = (a[i + n / 2] - a[(i + 1 + n / 2 ) % n]) * (a[i + n / 2] - a[(i + 1 + n / 2 ) % n]) + (b[i + n / 2] - b[(i + 1 + n / 2 ) % n]) * (b[i + n / 2] - b[(i + 1 + n / 2 ) % n]);
	    	if( slope2 == slope1 and dist1 == dist2 )
	    		ctr++;
	    }
	if( n % 2 == 1 or ctr != n / 2 )
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return(0);
}