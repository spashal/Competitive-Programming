#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[200005];
vector< pair< ll, ll> > ar;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; ar.pb(make_pair(a[i], i)); }
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ar.clear();
		ll ans = 0;
		ari;
		sort(ar.begin(), ar.end());
		ll curx = 0, cury = n - 1;
		for(int i = 0 ; curx <= cury and i < n ; i++){
			if( ar[i].ss < curx )
				continue;

			if( ar[i].ss == curx or ar[i].ss == cury ){
				if( curx == ar[i].ss )
					curx++;
				else
					cury--;
			}
			else{
				curx++;
				ans = curx;
				i--;
			}
		}
		cout << ans << endl;
	}
	return(0);
}