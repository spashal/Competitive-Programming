#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[105], b[105];
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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
    	cin >> t;
    	b[t]++;
    }
    vector< ll > ar;
    // for(int i = 0 ; i < 10 ; i++)
    // 	cout << b[i] << " ";
    // cout << endl;
    for(int i = 1 ; i <= 100 ; i++)
    	if( b[i] > 0 )
    		ar.pb(b[i]);
    for(int i = 0 ; i < n ; i++){
    	ll best_yet = -1, index = 0;
    	for(int j = 0 ; j < ar.size() ; j++)
    		if( best_yet < ar[j] / (a[j] + 1) ){
    			best_yet = ar[j] / (a[j] + 1);
    			index = j;
    		}
    	a[index]++;
    }
    // printar(ar, 0, ar.size());
    ll ans = 1e9;
    for(int i = 0 ; i < ar.size() ; i++)
    	if( a[i] > 0 )
    		ans = min(ans, ar[i] / a[i]);
    cout << ans << endl;
	return(0);
}