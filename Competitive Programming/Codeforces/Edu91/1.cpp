#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; pq.push(make_pair(a[i], i)); }
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
		priority_queue< pair< ll, ll>, vector< pair< ll, ll> > , greater< pair< ll, ll> > > pq;
		cin >> n;
		bool z = false;
		ari;
		ll minf = 0;
		for(int i = 1 ; i < n - 1 ; i++){
			while( !pq.empty() and i > pq.top().ss )
				pq.pop();
			if( a[i] > a[minf] and !pq.empty() and a[i] > pq.top().ff ){
				z = true;
				cout << "YES" << endl << minf + 1 << " " << i + 1 << " " << pq.top().ss + 1 << endl;
				break;
			}
			if( a[i] < a[minf] )
				minf = i;
		}
		if( !z )
			cout << "NO" << endl;
	}
	return(0);
}