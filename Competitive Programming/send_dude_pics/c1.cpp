#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], b[2005], c[2005];
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
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    	cin >> a[i] >> b[i] >> c[i];
    vector< pair<ll, pair< ll, ll> > > ar;
    for(int i = 0 ; i < n ; i++){
    	for(int j = i + 1 ; j < n ; j++){
    		ll ak = (a[j] - a[i]) * (a[j] - a[i]) + (b[j] - b[i]) * (b[j] - b[i]) + (c[j] - c[i]) * (c[j] - c[i]);
    		ar.pb(mp(ak, mp(i + 1, j + 1)));
    	}
    }
    vector< bool > vis(n + 1, false);
    sort(ar.begin(), ar.end());
    for(int i = 0 ; i < (n * (n - 1)) / 2 ; i++){
    	if( !vis[ar[i].ss.ff] and !vis[ar[i].ss.ss] and ar[i].ss.ss > 0 and ar[i].ss.ff > 0 ){
    		cout << ar[i].ss.ff << " " << ar[i].ss.ss << endl;
    		vis[ar[i].ss.ff] = true;
    		vis[ar[i].ss.ss] = true;
    	}
    }
	return(0);
}