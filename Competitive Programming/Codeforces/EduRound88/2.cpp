#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, x, y;

int main(){
	cin >> t;
	while( t-- ){
		ll ans = 0;
		char s[1005];
		cin >> n >> m >> x >> y;
		if( ( x * 2 ) <= y ){
			for( int i = 0 ; i < n ; i++ ){
				cin >> s;
				for( int j = 0 ; j < m ; j++ )
					if( s[j] == '.' )
						ans += x;
			}
			// cout << "yeay" << endl;
		}
		else{
			for( int i = 0 ; i < n ; i++ ){
				cin >> s;
				for( int j = 0 ; j < m ; j++ ){
					if( j < m - 1 and ( s[j] == '.' and s[j+1] == '.' )) {
						j++;
						ans += y;
					}
					else if( s[j] == '.' )
						ans += x;
				}
			}
		}
		cout << ans << endl;
	}
	return(0);
}