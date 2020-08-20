#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[1000005];
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
	for(int r = 1 ; r <= t ; r++){
		priority_queue< pair< ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > pq;
		cin >> n >> m;
		ari;
		vector< ll > ar(n + 1, -1);
		for(int i = 0 ; i <= m ; i++){
			ar[i] = 0;
			if( a[i] )
				pq.push(mp(a[i], i));
		}
		ll cur = m + 1, prev = m;
		while( !pq.empty() and cur < n ){
			cur = pq.top().ss + m;
			ll curcost = pq.top().ff;
			pq.pop();
			for(int i = prev + 1 ; i <= min(n, cur) ; i++)
				if( ar[i] == - 1){
				ar[i] = curcost;
				if( a[i] )
					pq.push(mp(curcost + a[i], i));
				}
			prev = cur;
			while( !pq.empty() and pq.top().ss < cur - m )
				pq.pop();
		}
		cout << "Case #" << r << ":" << ar[n - 1] << endl; 
	}
	return(0);
}