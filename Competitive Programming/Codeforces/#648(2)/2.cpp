#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[505], n, m, t, b[505];
vector< ll > adj[100005];
vector< ll > fir, sec;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < n ; i++ ) cin >> b[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;bri;
		ll z = 0 ;
		vector< pair< ll, ll> > ar;
		for( int i = 0 ; i < n ; i++ ){
			ar.push_back( make_pair( a[i], b[i]));
			if( b[i] > 0 )
				sec.push_back(a[i]);
			else
				fir.push_back(a[i]);
		}
		// sort( ar.begin(), ar.end());
		// ll j = 0;
		// ll k = 0;
		// for( int i = 0 ; i < n ; i++ ){
		// 	if( ar[i].second > 0 ){
		// 		if( ar[i].first != sec[j] ){
		// 			z = 1;
		// 			break;
		// 		}
		// 		j++;
		// 	}
		// 	else{
		// 		if( ar[i].first != fir[k] ){
		// 			z = 1;
		// 			break;
		// 		}
		// 		k++;
		// 	}
		// }

		if( sec.size() == 0 or fir.size() == 0 ){
			if( sec.size() > 0 ){
				sort( sec.begin(), sec.end());
				for( int i = 0 ; i < n ; i++ )
					if( a[i] != sec[i] )
						z++;
			}
			if( fir.size() > 0 ){
				sort( fir.begin(), fir.end());
				for( int i = 0 ; i < n ; i++ )
					if( a[i] != fir[i] )
						z++;
			}
			if( z )
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
		else
			cout << "Yes" << endl;
		fir.clear();
		sec.clear();
	}
	return(0);
}