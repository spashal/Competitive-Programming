#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
#define mp(a, b) make_pair(a, b)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
    	cin >> r >> a >> b;
    	arr.pb(mp(r, mp(a, b)));
    }
    sort(arr.begin(), arr.end());
    if( x1 > x2 ){
    	ll temp1 = x1, temp2 = y1;
    	x1 = x2;
    	y1 = y2;
    	x2 = temp1;
    	y2 = temp2;
    }
    for(int i = 0 ; i < n ; i++){
    	if( arr.ff < x1 )
    		continue;
    	if( arr.ff > x1 ){
    		ans = -1;
    		break;
    	}
    	
    }
	return(0);
}