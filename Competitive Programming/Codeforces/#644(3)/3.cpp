#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    vector< int > v;
	while( t-- ){
		cin >> n;
		int z = 0, e = 0, o = 0;

		for( int i = 0 ; i < n ; i++ ){
			int k;
			cin >> k;
			v.push_back(k);
			if( k % 2 ){
				o++;
			}
			else{
				e++;
			}
		}
		sort( v.begin(), v.end());
		if( e % 2 ){
			for( int i = 0 ; i < n ; i++ ){
				for( int j = 0 ; j < n ; j++ )
					if( ( v[i] + 1 ) == v[j] or ( v[i] - 1 ) == v[j] ){
						z = 1;
						break;
					}
				if( z == 1 )
					break;
			}
			if( z == 1 )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "YES" << endl;
		v.clear();
	}
	return(0);
}