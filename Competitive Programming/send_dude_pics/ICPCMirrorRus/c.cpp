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
    ll ctr = 0, ptr = 0;
    vector< ll > v, ans;
    vector< bool > done;

    priority_queue< pair< ll, pair< ll, ll> > > pq;
	while( t-- ){
		cin >> n;
		if( n == 1 ){
			ll tip;
			ctr++;
			cin >> tip;
			v.pb(ctr);
			pq.push(mp(tip, mp(t, ctr)));
			done.pb(0);
		}
		else if( n == 2 ){
			while( done[ptr] and ptr < done.size() )
				ptr++;
			if( done.size() > ptr ){
				// cout << v[ptr] << " " << done[ptr] << endl;
				ans.pb(v[ptr]);
				done[ptr] = 1;
			}
		}
		else{
			while( done[pq.top().sss - 1] and !pq.empty() )
				pq.pop();
			if( !pq.empty() ){
				ans.pb(pq.top().sss);
				done[pq.top().sss - 1] = 1;
				pq.pop();
			}
		}
	}
	for(int i = 0 ; i < ans.size() ; i++)
		cout << ans[i] << " ";
	cout << endl;
	return(0);
}