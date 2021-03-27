#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
		cin >> n >> m;
		ll sum = 0, cost = 0;
		vector< ll > a(n, 0), b(n, 0);
		priority_queue< pair<ld, pair<ll, ll> > > pq;
		vector< pair< ll, ll> > store;
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		for(int i = 0 ; i < n ; i++)
			cin >> b[i];
		for(int i = 0 ; i < n ; i++)
			pq.push(mp((ld)a[i]/b[i], mp(a[i], b[i])));
		while(!pq.empty()){
			store.pb(pq.top().ss);
			pq.pop();
		}
		vector< ll > next(n, -1);
		ll cur = -1;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(store[i].ss == 1)
				cur = i;
			next[i] = cur;
		}
		ll last = -1;
		for(int i = 0 ; i < n and sum < m ; i++){
			sum += store[i].ff;
			cost += store[i].ss;
			if(store[i].ss == 1)
				last = i;
			if(sum >= m and store[i].ss == 2){
				if(next[i] >= 0 and sum - store[i].ff + store[next[i]].ff >= m )
					cost--;
				else if(last >= 0 and sum - store[last].ff >= m)
					cost--;
			}
		}
		if(sum < m)
			cout << "-1\n";
		else
			cout << cost << endl;
	}
	return(0);
}