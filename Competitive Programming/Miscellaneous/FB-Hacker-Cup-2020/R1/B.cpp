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
		ll k, s, a, b, c, d;
		cin >> n >> m >> k >> s;
		vector< ll > p(n, 0), q(n, 0);
		for(int i = 0 ; i < k ; i++)
			cin >> p[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < n ; i++)
			p[i] = ((a * p[i - 2] + b * p[i - 1] + c) % d) + 1;

		for(int i = 0 ; i < k ; i++)
			cin >> q[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < m ; i++)
			q[i] = ((a * q[i - 2] + b * q[i - 1] + c) % d) + 1;

		sort(p.begin(), p.end());
		sort(q.begin(), q.end());

		printar(p, 0, n);
		printar(q, 0, m);
		vector< ll > pehle[n], baadme[n];
		vector< pair<ll, pair<bool, ll> > > ar;
		for(int i = 0 ; i < n ; i++)
			ar.pb(mp(p[i], mp(true, i)));
		for(int i = 0 ; i < m ; i++)
			ar.pb(mp(q[i], mp(false, i)));
		sort(ar.begin(), ar.end());
		ll l = 0, r = 0, prevlast = 0;
		for(int i = 0 ; i < n + m ; i++)
			if( ar[i].ss.ff ){
				for(int j = i - 1 ; j >= 0 ; j--)
					if( ar[j].ss.ff == false)
						pehle[ar[i].ss.ss].pb(ar[j].ss.ss);
					else
						break;
				for(int j = i + 1 ; j < n + m ; j++)
					if( ar[j].ss.ff == false )
						baadme[ar[i].ss.ss].pb(ar[j].ss.ss);
					else
						break;
			}
		vector< ll > dp[n];
		for(int i = 0 ; i < n ; i++){
			dp[i].resize(pehle[i].size() + baadme[i].size() + 1, 0);
			ll mana = INT_MAX;
			for(int j = 0 ; j < pehle[i].size() ; j++){
				dp[i][j] = 2 * (p[i] - q[pehle[i][j]]);
				if( i > 0 )
					dp[i][j] += dp[i - 1][pehle[i - 1].size() + j - 1];
				mana = min(dp[i][j], mana);
			}
			if( mana == INT_MAX )
				mana = 0;
			dp[i][pehle[i].size()] = mana;
			if( i > 0 )
				dp[i][pehle[i].size()] += dp[i - 1][pehle[i - 1].size() + baadme[i - 1].size()];
			for(int j = 0 ; j < baadme[i].size() ; j++)
				dp[i][j] = mana + q[baadme[i][j]] - p[i];
		}
		cout << dp[n - 1][pehle[n - 1].size() + baadme[n - 1].size()] << endl;
 	}
	return(0);
}