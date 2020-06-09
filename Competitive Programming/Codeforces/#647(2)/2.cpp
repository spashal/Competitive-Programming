#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k, m, po[15], a[1025];
vector< bool > s[1025];
vector< bool > ans;

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> p;
		for( int i = 0 ; i < n ; i++ ){
			cin >> a;
			k.push_back(a);
		}
		sort( k.begin(), k.end(), greater< int > ());
		a.push_back( k[0]);
		b.push_back( k[1]);
		if( k[0] > k[1] ){
			matterA = pow( p, k[0] - k[1]);
			matterB = 1;
		}
		else{
			matterA = k[0];
			matterB = k[1];
		}
		while( i < k.size() ){
			if( matterA > matterB and last == k[i] )
				matterB++;
			else if( matterA > matterB ){
				matterA = 
			}
		}
	}
	return(0);
}