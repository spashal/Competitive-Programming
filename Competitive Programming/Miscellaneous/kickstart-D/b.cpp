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

ll fatStack(vector<ll> &starts, ll num){
	vector<ll> :: iterator it = lower_bound(starts.begin(), starts.end(), num);
	return distance(starts.begin(), it);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int z = 1 ; z <= t ; z++){
		ll c;
		cin >> n >> c;
		vector<pair<ll, ll> > intervals;
		map<ll,ll> whoEnds;
		set<ll, 
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			ll aa, bb;
			cin >> aa >> bb;
			ans++;
			if(aa+1 == bb)
				continue;
			intervals.pb(aa);
			intervals.pb(bb);
		}
		sort(intervals.begin(), intervals.end());
		vector<ll> starts;
		for(int i = 0 ; i < intervals.size() ; i++)
			starts.pb(intervals[i].ff);
		priority_queue<pair<ll,ll> > pq;
		for(int i = 0 ; i < intervals.size() ; i++)
			pq.push(mp(fatStack(starts, intervals[i].ss)-i, i));
		while(!pq.empty() and c > 0)
			ll cur = pq.
		cout << "Case #" << z << ": " << ans << endl;
	}
	return(0);
}