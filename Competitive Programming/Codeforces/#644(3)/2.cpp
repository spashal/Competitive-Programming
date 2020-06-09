#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a[100], s[100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i];
		sort( a, a + n);
		// for( int i =0 ; i < n ; i++ )
		// 	cout << a[i] << " ";
		for( int i = 0 ; i < ( n - 1) ; i++ )
			s[i] = a[ i + 1 ] - a[i];
		sort( s, s + n - 1);
		cout << s[0] << endl;
	}
	return(0);
}