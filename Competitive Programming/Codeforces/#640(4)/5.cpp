#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int t, n, a[8005], ans;
int d[8005];
// bool c[8005];
set< int > v;
int main(){
	set <int> :: iterator itr;
	cin >> t;
	while( t-- ){
		cin >> n;
		// for( int i = 1 ; i <= n ; i++ ){
		// 	// b[i] = 0;
		// 	c[i] = 0;
		// 	// d[]
		// }
		for( int i = 0 ; i < n ; i++ ){
			cin >> a[i];
			d[i] = a[i];
		}
		// for( int i = 0 ; i < n ; i++ ){
		// 	if( b[a[i]] > 1 ){
		// 		ans++;
		// 		cout << i << " ";
		// 	}
		// }
		// cout << "ans is " << ans << endl;
		// for( int i = 0 ; i < )
		for( int i = 1 ; i < n ; i++ ){
			for( int j = 0 ; j + i < n ; j++ ){
				d[ j ] += a[ i + j ];
				if( d[j] <= n )
				v.insert(d[j]);
				// cout << v.back() << "*" << " ";
			}
		}
		// sort( v.begin(), v.end());
		for( int i = 0 ; i < n ; i++ ){
			itr = v.lower_bound(a[i]);
			if( *itr == a[i] ){
					ans++;
					// cout << i << "_" << a[i] << " ";
			}
				// else
					// cout << v[lower_bound( v.begin(), v.end(), a[i]) - v.begin()] << "* ";
			}
			
		// cout << endl;
		cout << ans << endl;
		ans = 0;
		v.clear();
	}
	return(0);
}