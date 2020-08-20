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

ll intrscn(ll x1, ll y1, ll x2, ll y2){
	if( x2 > x1 and x2 < y1 and y1 < y2 )
		return y1 - x2;
	else if( x1 > x2 and x1 < y2 and y2 < y1 )
		return y2 - x1;
	else if( x1 < x2 and y1 > y2 )
		return y2 - x2;
	else if( x2 < x1 and y2 > y1 )
		return y1 - x1;
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll l1, l2, r1, r2;
		cin >> n >> m;
		cin >> l1 >> r1 >> l2 >> r2;
		if( intrscn(l1, r1, l2, r2) == min(llabs(l1 - r1), llabs(l2 - r2)) ){
			// cout << intrscn(l1, r1, l2, r2) << endl;
			ll extra = max(llabs(l1 - r1), llabs(l2 - r2)) - min(llabs(l1 - r1), llabs(l2 - r2));
			if( n * extra >= m )
				cout << "0" << endl;
			else
				cout << 2 * m - n * extra << endl;
		}
		else if( intrscn(l1, r1, l2, r2) == 0 ){
			ll steps = llabs(l1 - l2) + llabs(r1 - r2);
			m -= (r2 + r1 - l1 - l2);
			if( r1 + r2 - l1 - l2 >= min(llabs(l1 - r2), llabs(l2 - r1)) ){
				steps *= (m / llabs(l1 - l2) + llabs(r1 - r2));
				m %= (llabs(l1 - l2) + llabs(r1 - r2));
				if( m >= min(llabs(r2 - l1), llabs(r1 - l2)) )
					cout << steps + m + min(llabs(r2 - l1), llabs(r1 - l2)) << endl;
				else
					cout << steps + 2 * m << endl; 
			}
			else{
				cout << steps + 2 * m << endl;
			}
		}
		else{
			ll temp = m;
			m -= n * min(llabs(l1 - r2), llabs(l2 - r1));
			if( m <= 0 )
				cout << "0" << endl;
			else
				cout << n * min(llabs(l1 - r2), llabs(l2 - r1)) + m * 2 << endl;
		}
	}
	return(0);
}