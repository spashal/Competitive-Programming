#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, x, l, r, a[100005];
		vector< pair< ll, ll> > p;
		vector< ll > q;

vector< ll > adj[100005];
vector< pair< ll, ll> > ar;
#define ari for( int i = 0 ; i < m ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		ll z[101];
		cin >> n >> x >> m;
		for( int i = 0 ; i < m ; i++ ){
			cin >> l >> r;
			ar.push_back(make_pair( l, r));
			z[i] = 0;
		}
		ll ans = 0;
		ll test = 0;
		for( int i = 0 ; i < m ; i++ ){
			if( x >= ar[i].first and x <= ar[i].second ){
				z[i] = 1;
				p.push_back(ar[i]);
				test++;
			}
		}
		if( test ){
		for( int i = 0 ; i < m  ; i++ ){
			for( int j = i + 1 ; j < m ; j++ ){
				if( i != j and z[i] and ar[i].first <= ar[j].second and ar[j].first <= ar[i].second){
					z[j] = 1;
					p.push_back(ar[j]);
				}
			}
		}
		ll j = 0;
		ll k = 0;
		sort( p.begin(), p.end());
		for( int i = 0 ; i < p.size() - 1 ; i++ ){
			if( p[i].first <= p[i+1].first and p[i].second >= p[i+1].first ){
				if( p[i].second < p[i+1].second ){
					p[i+1].first = p[i].first;
					q.push_back(i);
				}
				else{
					p[i+1].first = p[i].first;
					p[i+1].second = p[i].second;
					q.push_back(i);
				}
			}
		}
		for( int i = 0 ; i < p.size() ; i++ ){
				if( j < q.size() and q[j] == i )
					j++;
				else
					ans += p[i].second - p[i].first + 1;
				
		}}
		if( test == 0 )
			cout << "1" << endl;
		else
			cout << ans << endl;
		ar.clear();
		p.clear();
		q.clear();
	}
	return(0);
}