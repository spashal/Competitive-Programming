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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		vector< ll > pos, neg;
		vector< pair< ll, ll> > ar;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			ar.pb(mp(llabs(a[i]), a[i]));
			if( a[i] > -1 )
				pos.pb(a[i]);
			else
				neg.pb(a[i]);
		}
		sort(ar.begin(), ar.end());
		sort(pos.begin(), pos.end(), greater< ll > ());
		sort(neg.begin(), neg.end());
		ll ans = -1000000000000000000;
		if( neg.size() >= 4 and pos.size() >= 1 )
			ans = max(ans, neg[0] * neg[1] * neg[2] * neg[3] * pos[0]);
		if( neg.size() >= 2 and pos.size() >= 3 )
			ans = max(ans, neg[0] * neg[1] * pos[1] * pos[2] * pos[0]);
		if( pos.size() >= 5 )
			ans = max(ans, pos[0] * pos[1] * pos[2] * pos[3] * pos[4]);
		if( ans < 0 ){
			ans = max(ans, ar[0].ss * ar[1].ss * ar[2].ss * ar[3].ss * ar[4].ss);
		}
		cout << ans << endl;
	}
	return(0);
}