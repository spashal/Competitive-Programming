#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k, m, a[1025];
vector< ll > ans;

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		sort( a, a + n);
		ll z = -1;
		for( int i = 1 ; i < 1024 ; i++ ){
			for( int j = 0 ; j < n ; j++ )
				ans.push_back(a[j]^i);
			sort( ans.begin(), ans.end());
			ll T = 0;
			for( int j = 0 ; j < n ; j++ )
				if( ans[j] == a[j] )
					T++;
			ans.clear();
			if( T == n ){
				z = i;
				break;
			}
		}
		cout << z << endl;
	}
	return(0);
}