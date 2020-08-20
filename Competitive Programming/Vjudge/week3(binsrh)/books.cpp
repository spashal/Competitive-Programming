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
    cin >> n >> t;
    vector< int > ar;
    ar.pb(0);
    for(int i = 1 ; i <= n ; i++){
    	cin >> m;
    	ar.pb(ar[i - 1] + m);
    }
    int maxi = 0;
    vector< int > :: iterator it;
    for(int i = 0 ; i < n ; i++){
    	it = lower_bound(ar.begin(), ar.end(), t + ar[i]);
    	// cout << *it << " " << it - ar.end() << endl;
    	if( *it == (t + ar[i]) )
	    	maxi = max(maxi, (int)(it - ar.begin()) - i);
	    else
	    	maxi = max(maxi, (int)(it - ar.begin()) - i - 1);
    }
    cout << maxi << endl;
	return(0);
}