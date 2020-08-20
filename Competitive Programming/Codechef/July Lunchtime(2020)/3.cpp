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
    cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		vector< pair< ll, ll> > ar;
		for(int i = 0 ; i < n ; i++){
			ll temp = a[i], ctr = 0;
			while(temp){
				temp /= 2;
				ctr++;
			}
			ar.pb(mp(a[i], ctr));
		}
		sort(ar.begin(), ar.end(), greater< pair<ll, ll> > ());
		if( n > 1 ){
			ll temp1 = a[n - 1], ctr1 = 0, temp2 = a[0], ctr2 = 0;
			while(temp1){
				temp1 /= 2;
				ctr1++;
			}
			while(temp2){
				temp2 /= 2;
				ctr2++;
			}
			ll k = a[n - 1] + (1 << ctr1) * a[0];
			ll l = a[0] + (1 << ctr2) * a[n - 1];
			cout << llabs(k - l) << endl;
		}
		else
			cout << "0" << endl;
	}
	return(0);
}