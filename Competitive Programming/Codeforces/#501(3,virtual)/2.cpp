#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, z = 0;
int a[256], b[256];

int main(){
	vector< int > v;
	char s[55], t[55];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
	cin >> s;
	cin >> t;
	for( int i = 0 ; i < n ; i++ ){
		a[s[i]]++;
		b[t[i]]++;
	}
	for( int i = 0 ; i < 256 ; i++ )
		if( a[i] != b[i] ){
			z = 1;
			cout << "-1" << endl;
			break;
		}
	if( z == 0 ){
		for( int i = n - 1 ; i > -1 ; i-- ){
			int j = 0;
			while( s[j] != t[i] )
				j++;
			for( int k = j + 1 ; k <= i ; k++ ){
				v.push_back(k);
				char temp = s[ k - 1 ];
				s[ k - 1 ] = s[k];
				s[k] = temp;
			}
		}
		cout << (int)v.size() << endl;
		for( int i = 0 ; i < v.size() ; i++ )
			cout << v[i] << " ";
		cout << endl;
	}
	return(0);
}