#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ll z = 0;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		sort( a, a + n);
		ll prev = a[n-1];
	
		for( int i = 0 ; i < n ; i++ )
			// if( i + 1 < a[i] and i < n - 1 and a[i] == a[i+1] ){
				// cout << i << " " << endl;
			// }
			if( i + 1 >= a[i] ){
				z = i + 1;
				// break;
			}
		if( z == 0 )
			cout << 1 << endl;
		else
			cout << z + 1 << endl;
	}
	return(0);
}