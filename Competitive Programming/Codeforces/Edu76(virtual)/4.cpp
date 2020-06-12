#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
vector< pair< ll, ll> > ar;
vector< ll > c, p, s, a;
#define ari for( int i = 0 ; i < n ; i++ ){ a.push_back(0);cin >> a[i]; } 
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		cin >> m;
		for( int i = 0 ; i < m ; i++ ){
			ar.push_back(make_pair(0, 0));
			cin >> ar[i].first >> ar[i].second;
			c.push_back(0);
		}
		sort( ar.begin(), ar.end());
		c[m-1] = m-1;
		ll ma = m-1;
		for( int i = m-2 ; i > -1 ; i-- ){
			if( ar[i].second > ar[ma].second )
				ma = i;
			c[i] = ma;
		}
		ll z = 0;
		for( int i = 0 ; i < m ; i++ ){
			p.push_back(ar[i].first);
			s.push_back(ar[i].second);
		}
		ll days = 1;
		ll prev = (ll)(lower_bound(p.begin(), p.end(), a[0]) - p.begin());
		if( prev != m )
		prev = c[prev];
		if( prev == m or a[0] > p[prev] ){
			z = 1;
		}
		if( !z ){
			ll carry = 1;
			for( int i = 1 ; i < n ; i++ ){
				if( p[prev] >= a[i] and carry <= s[prev] - 1 )
					carry++;
				else{
					days++;
					ll j = (ll)( lower_bound(p.begin(), p.end(), a[i]) - p.begin());
					if( j == m or a[i] > p[c[j]] ){
						z = 1;
						break;
					}
					prev = c[j];
					carry = 1;
				}
			}
		}
		if( z )
			cout << "-1" << endl;
		else
			cout << days << endl;
		ar.clear();
		s.clear();p.clear();c.clear();a.clear();
 	}
	return(0);
}