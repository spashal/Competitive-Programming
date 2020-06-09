#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, a, b;
vector< int > v;

bool sorty( pair< int, int> a, pair< int, int> b){
	if( a.first == b.first )
		return b.second > a.second;
	return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll ini = 0;
	ll k = 0, z = 0;
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a >> b;
		v.push_back( a - b );
		ini += a;
	}
	sort( v.begin(), v.end(), greater< int >());
	for( int i = 0 ; i < n ; i++ ){
		if( ini > m ){
			k++;
			ini -= v[i];
		}
		if( ini <= m ){
			cout << k << endl;
			z = 1;
			break;
		}
	}
	if( z == 0 )
		cout << "-1" << endl;
	return(0);
}