#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, x, y;
bool a[105];
vector< pair< int, int> > v;
vector< int > k;

bool sorty( pair< int, int> a, pair< int, int> b){
	if( a.first == b.first )
		return b.second > a.second;
	return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ ){
		cin >> x >> y;
		v.push_back( make_pair( x, y));
	}
	sort( v.begin(), v.end(), sorty);
	for( int i = 0 ; i < n ; i++ )
		for( int j = v[i].first ; j <= v[i].second ; j++ )
			a[j] = 1;
	for( int i = 1 ; i <= m ; i++ )
		if( !a[i] )
			k.push_back(i);
	cout << (int)k.size() << endl;
	if( k.size() )
		for( int i = 0 ; i < k.size() ; i++ )
			cout << k[i] << " ";
	cout << endl;
	return(0);
}