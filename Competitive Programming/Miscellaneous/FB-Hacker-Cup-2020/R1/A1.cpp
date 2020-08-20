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
    ll mod = 1e9 + 7;
    cin >> t;
	for(int j = 1 ; j <= t ; j++){
		ll k, w, a, b, c, d, ans = 1;
		cin >> n >> k >> w;
		vector< ll > l(n, 0), h(n, 0);
		priority_queue< pair<ll, ll> > pq;

		for(int i = 0 ; i < k ; i++)
			cin >> l[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < n ; i++)
			l[i] = (a * l[i - 2] + b * l[i - 1] + c) % d + 1;
		for(int i = 0 ; i < k ; i++)
			cin >> h[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < n ; i++)
			h[i] = (a * h[i - 2] + b * h[i - 1] + c) % d + 1;

		ll prevx = 0, per_yet = 0;
		for(int i = 0 ; i < n ; i++){
			while( !pq.empty() and pq.top().ss < l[i] )
				pq.pop();
			if( prevx >= l[i] ){
				per_yet += (2 * (w + h[i]) - 2 * (prevx - l[i]) - 2 * min(pq.top().ff, h[i]));
				per_yet %= mod;
				ans = (ans * per_yet) % mod;
				prevx = l[i] + w;
			}
			else{
				per_yet += 2 * (w + h[i]);
				per_yet %= mod;
				ans = (ans * per_yet) % mod;
				prevx = l[i] + w;
			}
			pq.push(mp(h[i], l[i] + w));
			cout << per_yet << endl;
		}
		cout << "Case #" << j << ": ";
		cout << ans << endl;
	}
	return(0);
}