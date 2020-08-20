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
    ll k;
    cin >> k;
    if( k % 2 == 0 or k % 5 == 0 ){
    	cout << "-1" << endl;
    	return(0);
    }
    ll po = (7 % k), prev = 0, ans = 0;
    for(int i = 1 ; ; i++){
    	if( (po + prev) % k == 0 ){
    		ans = i;
    		break;
    	}
    	prev = (po + prev) % k;
    	po = (po * 10) % k;
    }
    cout << ans << endl;
	return(0);
}